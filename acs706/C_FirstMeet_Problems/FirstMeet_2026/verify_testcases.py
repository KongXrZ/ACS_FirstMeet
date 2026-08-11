import json
import subprocess
import os
import sys

def main():
    # 1. Compile temple.c
    print("Compiling temple.c...")
    compile_cmd = ["gcc", "temple.c", "-o", "temple.exe"]
    compile_result = subprocess.run(compile_cmd, capture_output=True, text=True)
    
    if compile_result.returncode != 0:
        print("Compilation failed!")
        print(compile_result.stderr)
        sys.exit(1)
        
    print("Compilation successful.")
    
    # 2. Read testcases
    json_path = "testcase-import-temple.json"
    if not os.path.exists(json_path):
        print(f"Error: {json_path} not found.")
        sys.exit(1)
        
    with open(json_path, "r", encoding="utf-8") as f:
        data = json.load(f)
        
    test_cases = data.get("testCases", [])
    total_cases = len(test_cases)
    
    print(f"Loaded {total_cases} test cases. Starting verification...\n")
    
    passed = 0
    exe_path = "./temple.exe" if os.name != 'nt' else "temple.exe"
    
    for i, tc in enumerate(test_cases):
        input_data = tc["input"]
        expected_output = tc["output"]
        
        # Run the executable with the input
        run_result = subprocess.run(
            [exe_path], 
            input=input_data, 
            capture_output=True, 
            text=True
        )
        
        actual_output = run_result.stdout
        
        # We replace \r\n with \n to avoid cross-platform newline issues
        actual_output_normalized = actual_output.replace('\r\n', '\n')
        expected_output_normalized = expected_output.replace('\r\n', '\n')
        
        if actual_output_normalized == expected_output_normalized:
            passed += 1
            print(f"Test case {i+1}/{total_cases} [PASS]")
        else:
            print(f"Test case {i+1}/{total_cases} [FAIL]")
            print(f"Input:\n{input_data.strip()}")
            print(f"Expected:\n{expected_output_normalized.strip()}")
            print(f"Actual:\n{actual_output_normalized.strip()}")
            print("-" * 40)
            
    print(f"\nVerification Complete: {passed}/{total_cases} test cases passed.")

if __name__ == "__main__":
    main()
