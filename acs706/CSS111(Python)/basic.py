secs = int(input())
hr = secs // 3600
min_ = secs // 60
sec = (secs //3600) % 60
print(f"{hr} ชั่วโมง {min_} นาที {sec} วินาที")