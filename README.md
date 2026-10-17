# C++ Financial Mathematics — Chapter Review & MyLib

A chapter-by-chapter implementation and refactor of John Armstrong's "C++ for Financial Mathematics" with exercises, example programs, and a gradually refactored library (MyLib) alongside original FMLib variants for comparison.

## What this repository is
This repo is a study + reference implementation of financial-maths examples in C++ — exercises and small apps for each book chapter, plus a progressive refactor into a reusable library (MyLib) and preserved original library versions (FMLib*).

### Notable contents / stack
- Language: C++ (source under chapter folders and MyLib)
- Build artifacts: several Xcode project files appear (MyLib.xcodeproj, FMLib.xcodeproj in chapter folders). No single repo-wide CMake/Make manifest was detected at root.

## Top-level structure
```
MyLib/                      -- Refactored library, include/ and src/ with option pricing, Monte Carlo, plotting helpers
FMLib15_Original/           -- Original source/library from the book (chapter-specific)
chap_0/ .. chap_11/         -- Chapter folders: exercises, example programs, slides and small projects
chap_5_finale/              -- Final version of chapter 5 exercises (includes MyLib snapshot)
chap_5_FMLib5/ chap_6_FMLib6/ .. chap_9_FMLib9/  -- Book FMLib variants per chapter
00 - Take Notes while reading.docx
.gitignore
```

## How it fits together
Examples and chapter programs either use the original FMLib code (FMLib*/chap_* folders) or the refactored MyLib library. MyLib provides option classes, pricing models, Monte Carlo pricers, and small charting helpers; chapter mains and examples exercise these components to produce CSV/HTML outputs and visualizations.

## How to use / build
There is no single cross-platform build manifest checked into the repo root. Typical ways to run or build examples:

- macOS / Xcode: open the provided `.xcodeproj` files (e.g. `MyLib/MyLib.xcodeproj` or `chap_9_FMLib9/FMLib.xcodeproj`) and build/run the example targets.

- g++ / command line (example): to compile an example using MyLib sources, from the repository root:

```bash
mkdir -p build && cd build
# Example: build a chapter/example that uses MyLib/src (adjust files as needed)
# -I points to MyLib/include. Add the specific .cpp files for the example or use a glob if your shell supports it.
g++ -std=c++17 -I../MyLib/include ../MyLib/src/*.cpp ../MyLib/src/main.cpp -o chapter_example
./chapter_example
```

- Inspect CSV/HTML outputs: some examples produce `simulated_prices.csv` and `examplePricePath.html` in `MyLib/` which you can open in a browser to visualize results.

If you want, I can add a small CMakeLists.txt or a top-level Makefile and example build targets.

## Per-folder summary (chapter-by-chapter)
- MyLib/
  - include/ and src/ contain the refactored library code: option classes (Call/Put/Asian/Digital), Black–Scholes model, Monte Carlo pricer, hedging simulator, math helpers (`matlib`), charting helpers (LineChart, PieChart, Histogram), small notebooks and example outputs (HTML/CSV).
  - Notable source files: `BlackScholesModel.cpp`, `MonteCarloPricer.cpp`, `HedgingSimulator.cpp`, `LineChart.cpp`, `matlib.cpp`, `charts.cpp`.

- FMLib15_Original/
  - Preserved original library/archive from the book for reference/comparison.

- chap_0/
  - Initial notes and simple examples (introductory material).

- chap_1/
  - Simple calculators and PDF slides: includes `cpp-chapter1-slides.pdf` and small calculator example folders (Interest Calculator, ProfitCalculator, ExamCalculator).

- chap_2/ .. chap_4/
  - Exercise and example folders for each chapter — code samples and small apps corresponding to book exercises.

- chap_5_FMLib5/ and chap_5_finale/
  - Chapter 5 implementations: `chap_5_finale` contains a polished snapshot of the chapter 5 work and a MyLib copy in that folder.

- chap_6/ chap_6_FMLib6/ chap_7_FMLib7/ chap_8_FMLib8/ chap_9_FMLib9/
  - Chapter-specific libraries and examples. `chap_9_FMLib9` contains a complete example set including `BlackScholesModel.*`, `MonteCarloPricer.*`, `matlib.*`, charting sources and a `main.cpp` demonstrating usage.

- chap_10/ chap_11/ chap_11_mag/
  - Later chapters and your annotated variants (e.g., `chap_11_mag` likely contains your notes or extended solutions for chapter 11).

Notes: Many chapter folders contain both original FMLib implementations and your refactored MyLib code; some folders include Xcode projects (`.xcodeproj`) and auxiliary outputs (CSV/HTML/PDF).

## Suggested next small improvements I can make for you
1. Add a top-level CMakeLists.txt and a small CMake target to build MyLib and one or two chapter examples cross-platform.
2. Create a CONTRIBUTING.md with how you want collaborators to run examples and where to add new chapter work.
3. Generate a table-of-contents section in this README linking to each chapter and its main example files.
4. Add a short badge and a run/test script for quickly building a small example in CI.

## Try asking
- "Can you add a CMakeLists.txt that builds MyLib and chap_9_FMLib9/main.cpp?"
- "Show me the API surface of MyLib: list public headers in MyLib/include and their classes/functions."
- "Make a small example that runs the Monte Carlo pricer and outputs simulated_prices.csv, then add a script to build and run it."
