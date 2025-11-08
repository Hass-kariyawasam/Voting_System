## Quick orientation

This repository is a C-language, text-file backed simulation of the Sri Lanka Parliamentary voting workflow. It is a menu-driven, console program (Windows-oriented) with role-based interfaces (Admin, RO, PO, Voter, Party Agent).

Work happens in the `scr/` directory (source) and `data/` (text files used as the datastore). The program is compiled into a single executable (`hima.exe`) via the provided batch script `scr/compile_run.bat`.

## Big-picture architecture

- UI & menus: `scr/ui.c`, `scr/main.c`, `scr/ui.c` holds the main menu and role-specific screens. Helper declarations live in `scr/custom.h`.
- Core logic split across many C files in `scr/` (e.g., `registration.c`, `admin.c`, `election_admin.c`, `party_agent.c`, `voter_polling.c`, `calculate.c`). Functions are mostly global C functions called from menu handlers.
- Persistence: flat text files in `data/` and `admin/` (for presiding officers). Typical files: `voters.txt`, `candidates.txt`, `parties.txt`, `districts.txt`, `pooling.txt`, and per-party nomination files in `data/nomination_list/`.

Why this structure: the project favors simple, portable C code and text-based persistence to avoid database setup and keep the educational focus on election logic rather than infra.

## Important developer workflows

- Build & run (Windows - PowerShell / cmd): run the provided batch to compile and start the app.
  - `scr/compile_run.bat` uses `gcc` to compile all `.c` files into `hima` and then launches `hima.exe`.
  - If editing on Windows with MinGW or WSL, ensure `gcc` is on PATH. On Linux/macOS use an equivalent `gcc` command (see the batch contents for the compile line).

- Quick compile command (POSIX-like):
  - gcc Admin_loging.c voter_polling.c main.c calculate.c compenents.c ui.c registration.c admin.c election_admin.c party_agent.c PO.c RO.c -o hima

## File & data conventions agents should know

- Text file record separators: most data files use pipe `|` delimited fields with one record per line.
  - `data/parties.txt` format: PARTY_ID|PARTY_NAME
  - `data/districts.txt` format: DISTRICT_ID|DISTRICT_NAME|SEAT_COUNT
  - `data/candidates.txt` example: CAND_SEQ|NIC|NAME|AGE|ELIGIBLE|USERNAME|DISTRICT_ID|PARTY_ID
  - `data/voters.txt` example: NIC|NAME|AGE|ELIGIBLE|PASSWORD|DISTRICT_ID
  - Nomination files: `data/nomination_list/PA_<partyID>_nomination.txt` contain candidate lines usually as `CANDIDATE_ID|NAME|AGE|DISTRICT|...` (see `scr/ui.c` reading code for exact fscanf patterns).

- Paths in source: source files use relative paths to `../data/` and `../admin/` because `scr/` is the CWD during development. When running from the repo root, prefer running `scr/compile_run.bat` which handles launching from `scr/`.

## Coding patterns & conventions

- Minimal, procedural C: functions are free-floating, long source files, and global macros for file paths (see `scr/ui.c` for `#define` constants like `PARTY_FILE`).
- Error handling: routines often check for NULL FILE pointers and call UI helpers (`pressEnterToContinue()`, `time_delay()`) before returning to menus — replicate that style when adding features.
- UI uses Windows-specific helpers: `system("cls")`, `color()` (from `custom.h`) and `windows.h` are used; take care if porting to other OSes.

## Tests & debugging

- No automated test harness is present. Use the compile script and run the program to exercise flows manually.
- For fast debugging: add temporary printf() lines and re-run `scr/compile_run.bat`. When changing file formats, update both writer and reader in source files (search for the `fscanf` patterns in `scr/` to find read logic).

## Examples to reference when changing behavior

- To see data parsing examples, inspect `scr/ui.c` functions `public_nomination_list()` and the `fscanf` patterns used when iterating nomination files.
- The compile script: `scr/compile_run.bat` shows the full compile command and run invocation.
- The central menu flow is in `scr/main.c` and `scr/ui.c` — change these to add top-level menu items.

## What an AI agent should do first

1. Read `scr/ui.c`, `scr/main.c`, and `scr/custom.h` to learn menu flow and helper functions.
2. Inspect `data/` files to understand current record formats before editing any reader/writer code.
3. Run `scr/compile_run.bat` locally to reproduce the runtime and surface build issues.

## Do not assume / watch-outs

- Do not assume field order — verify by reading the matching `fscanf`/`fprintf` statement in the C file that reads or writes that particular file.
- Beware that file paths are relative to `scr/` in many places; changing working directory or running the binary from another folder will require path adjustments.

If anything here is ambiguous or you'd like me to include more examples (specific functions, more data files, or a small unit test harness), tell me which area to expand and I will iterate.
