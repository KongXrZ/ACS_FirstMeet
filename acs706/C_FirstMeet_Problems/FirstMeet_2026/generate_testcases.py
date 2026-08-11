import json
import random

def generate_output(blocks, height, width):
    output = ""
    for _ in range(blocks):
        for _ in range(height):
            output += "*" * width + "\n"
        output += "-" * width + "\n"
    return output

def create_testcase(blocks, height, width, is_sample=False):
    return {
        "input": f"{blocks} {height} {width}\n",
        "output": generate_output(blocks, height, width),
        "isSample": is_sample
    }

def main():
    random.seed(42)  # For reproducibility
    
    test_cases = []
    
    # 15 Edge Cases
    edge_params = [
        (1, 1, 1), (50, 50, 50), (1, 50, 50), (50, 1, 50), 
        (50, 50, 1), (1, 1, 50), (1, 50, 1), (50, 1, 1),
        (2, 2, 2), (49, 49, 49), (1, 2, 3), (50, 49, 48),
        (25, 1, 25), (10, 50, 10), (50, 10, 50)
    ]
    
    # 35 Normal Cases
    normal_params = [
        (2, 2, 2),
        (3, 2, 4),
        (2, 6, 7)
    ]
    while len(normal_params) < 35:
        b = random.randint(2, 49)
        h = random.randint(2, 49)
        w = random.randint(2, 49)
        normal_params.append((b, h, w))
        
    # Build testCases array
    # 2 sample cases from normal cases
    for i, (b, h, w) in enumerate(normal_params):
        is_sample = True if i < 2 else False
        test_cases.append(create_testcase(b, h, w, is_sample))
        
    for (b, h, w) in edge_params:
        test_cases.append(create_testcase(b, h, w, False))
        
    # The total will be 50 test cases (35 normal, 15 edge)
    
    output_json = {
        "version": 1,
        "testCases": test_cases
    }
    
    out_path = "testcase-import-temple.json"
    with open(out_path, "w", encoding="utf-8") as f:
        json.dump(output_json, f, indent=2)
        
    print(f"Successfully generated 50 test cases in {out_path}")

if __name__ == "__main__":
    main()
