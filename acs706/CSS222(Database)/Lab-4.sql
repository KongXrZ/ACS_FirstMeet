use sakila;

--HW_1
SELECT film.*, language.name AS language_name
FROM film 
JOIN language USING(language_id);

--HW_2
SELECT first_name, last_name, city 
FROM customer 
JOIN address USING(address_id)
JOIN city USING(city_id);

--HW_3
SELECT title, first_name, last_name 
FROM film 
JOIN film_actor USING(film_id)
JOIN actor USING(actor_id);

--HW_4
SELECT film.*
FROM customer
JOIN rental USING(customer_id)
JOIN inventory USING(inventory_id)
JOIN film USING(film_id)
WHERE first_name = "Mary" AND last_name = "Smith";

--HW_5
SELECT staff.*, district, address 
FROM staff
JOIN store USING(store_id)
JOIN address ON store.address_id = address.address_id;

--HW_6
SELECT first_name, last_name, rental_id 
FROM customer
LEFT JOIN rental USING(customer_id);


use university;

--HW_7
SELECT ID, name, COUNT(sec_id)
FROM instructor
LEFT JOIN teaches USING(ID)
GROUP BY ID, name;

--HW_8
SELECT title, section.sec_id, name
FROM instructor
JOIN teaches USING(ID)
JOIN course USING(course_id)
JOIN section USING (course_id, sec_id, semester, year)
WHERE section.semester = "Spring" AND section.year = 2010;

--HW_9
SELECT dept_name , COUNT(ID) 
FROM department
LEFT JOIN instructor USING(dept_name)
GROUP BY dept_name;