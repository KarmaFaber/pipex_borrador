# Test Directory Documentation

This directory contains scripts, outputs, and configurations for testing the `pipex` project. Below is an overview of its structure and how to utilize the provided resources.

## Directory Structure

```
/test
├── commands.txt           # List of commands used for testing.
├── hs_files/              # Helper scripts for managing and running tests.
│   ├── clean_test.sh      # Cleans test-generated files.
│   ├── clean_valgrind.sh  # Cleans valgrind output files.
│   ├── open_valgrind_log.sh # Opens the latest valgrind log.
│   ├── special_cases.sh   # Runs special test cases.
│   └── test_pipex.sh      # Main script for running common tests.
├── test_outputs/          # Directory for test output files.
├── valgrind_outputs/      # Directory for valgrind log files.
```

## Prerequisites

Before running any tests, ensure that:
- The `pipex` executable is compiled and available in the project root.
- All scripts in `hs_files` have execution permissions. You can grant these permissions using:

  ```bash
  chmod +x test/hs_files/*.sh
  ```

- The necessary files like `infile` and `outfile` exist or are generated during the test process.

## Available Commands

### Makefile Targets

The `test` directory has its own `Makefile` that facilitates testing. The following commands are available:


- **`make norm`**
  - Runs the `norminette` check on the project and test scripts.

	```bash
	make norm
	```

- **`make test`**
  - more typical cases (included in the subject) + slightly more specific cases
  	```bash
	make test
	```

- **`make test_all`**
  - Runs all tests, including norm checks, valgrind, and sanitizers.
  	```bash
	make test_all
	```

- **`make valgrind`**
  - Executes the `pipex` program under valgrind to check for memory leaks.
  	```bash
	make valgrind
	```

- **`make san_all`**
  - Compiles and runs the project with all supported sanitizers:
    - AddressSanitizer
    - UndefinedBehaviorSanitizer
    - LeakSanitizer
    - ThreadSanitizer
  	```bash
	make san_all
	```

- **Sanitizer-specific targets**:
  - `make run_asan`: Runs with AddressSanitizer.
  - `make run_usan`: Runs with UndefinedBehaviorSanitizer.
  - `make run_lsan`: Runs with LeakSanitizer.
  - `make run_tsan`: Runs with ThreadSanitizer.

- **Cleanup Targets**
This commands will ask the user if he/she wants to delete temporary files: 
```bash
⚠️  Warning: Are you sure you want to delete all test stats? (y/n).

🛑 Warning: Are you sure you want to delete all Valgrind log files? (y/n)
```

⚠️  Warning: Are you sure you want to delete all test stats? (y/n)


  - `make clean_test`: Cleans test-related files such as `infile`, `outfile`, and temporary files. 
  - `make clean_valgrind`: Deletes all valgrind logs. 
  - `make fclean_test`: Performs a full cleanup of compiled files of proyect and cleans test-related files such as `infile`, `outfile`, and temporary files.. 
  - `make fclean_all`: Performs a full cleanup of test and compiled files of proyect. 

## Testing Workflow

1. **Setup**:
   Ensure `pipex` is compiled by running:
   ```bash
   make -C ../
   ```

2. **Run Tests**:
   Execute the desired test target. For example:
   ```bash
   make test
   make valgrind
   ```

3. **Review Results**:
   Check the output files in the `test_outputs` directory and valgrind logs in `valgrind_outputs`.

4. **Cleanup**:

   -Remove temporary **all** files: fclean (libft + pipex) + clean_test + clean_valgrind
   ```bash
   make fclean_all
   ```
   -Remove temporary test files and proyect object files: fclean (libft + pipex) + clean_test 
   ```bash
   make fclean_test
   ```

   -Remove temporary **test** files using:
   ```bash
   make clean_test
   ```

   -Remove temporary **Vangrind** files using:
   ```bash
   make clean_valgrind
   ```

## Notes

- Modify `commands.txt` and `special_cases.sh` to include any additional test cases specific to your implementation.
- Review `commands.txt` for a list of standard commands used during testing and `special_cases.sh` for special cases. 

## ➾ Contributing

* Check the open issues or open a new issue to start a discussion around your feature idea or the bug you found. 
* Fork the repository, make your changes, and add yourself to AUTHORS.md
* Send a pull request.

## ➾ Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 


## ➾ Authors

* [Karma Faber](https://github.com/KarmaFaber). 


## ➾ License

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or distribute this software, either in source code form or as a compiled binary, for any purpose, commercial or non-commercial, and by any means.

In jurisdictions that recognize copyright laws, the author or authors of this software dedicate any and all copyright interest in the software to the public domain. We make this dedication for the benefit of the public at large and to the detriment of our heirs and successors. We intend this dedication to be an overt act of relinquishment in perpetuity of all present and future rights to this software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

