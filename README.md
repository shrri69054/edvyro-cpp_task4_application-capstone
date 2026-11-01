# C++ Application Capstone

Release-ready version of the library manager with separated headers/implementation, reporting, persistence, validation, and tests.

## Build with CMake
```bash
cmake -S . -B build
cmake --build build
```

## Run
Linux/macOS:
```bash
./build/library_app
./build/library_tests
```
Windows:
```powershell
build\Debug\library_app.exe
build\Debug\library_tests.exe
```

## Requirements covered
- Clean header/source separation
- Error handling and invalid-input recovery
- Local persistence in `library_data.txt`
- Search, borrow, return
- Availability analytics/report
- Automated tests
- C++17 standard library containers and RAII-based file streams

## Complexity note
- Search: O(n)
- Borrow/return: O(n)
- Availability report: O(n)
- Storage: O(n)

## Second-environment check
Build the project with a second compiler or environment and record the result in `BUILD_VERIFICATION.md`.
