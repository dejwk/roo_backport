# roo_backport 1.3.0

- Add `roo::countr_zero` with the standard zero-input result and C++11 support.

---

# roo_backport 1.2.5

- Added Bazel tests for `roo::byte`, `roo::move`, and `roo::string_view` in C++11 and C++17. GitHub Actions now runs tests on the host and nine embedded profiles covering ESP32, ESP32-C3, ESP32-S3, and RP2040.
- Added a Bazelisk wrapper and a script to run tests locally across all nine embedded profiles.
- Configured the roo Bazel registry, added `roo_testing` 2.6.0 as a Bazel development dependency, and upgraded the shared CI workflow from `roo_testing` 2.0.0 to 2.6.0.
- Declared the library headers as public in the Bazel target.
- Added shared C++ formatting settings and contributor guidance for embedded C++ and design documents.

---

# roo_backport 1.2.4

## Changed

- Updated the Bazel `rules_cc` dependency to version 0.2.25.

---
# [roo_backport 1.2.3](https://github.com/dejwk/roo_backport/releases/tag/1.2.3)

Published 2026-08-21.

# roo_backport 1.2.3

## Changed

- Added GitHub Actions CI for pushes, pull requests, and manual runs.
- Added Bazel 9.2.0 toolchain configuration.
- Added centralized AddressSanitizer support for Bazel builds.

## Notes

No library API or functional changes are included in this release.

---

# [1.2.2](https://github.com/dejwk/roo_backport/releases/tag/1.2.2)

Published 2026-02-24.

Testing: updated the rules_cc dependency.

**Full Changelog**: https://github.com/dejwk/roo_backport/compare/1.2.1...1.2.2

---

# [roo_backport 1.2.1](https://github.com/dejwk/roo_backport/releases/tag/1.2.1)

Published 2026-01-25.

Fixed testing build files to work with the most recent versions of bazel.

---

# [roo_backport 1.2.0](https://github.com/dejwk/roo_backport/releases/tag/1.2.0)

Published 2026-01-06.

* Fixed compilation issues on Raspberry Pi Pico.
* Confirmed to work with esp-idf.

**Full Changelog**: https://github.com/dejwk/roo_backport/compare/1.1.1...1.2.0

---

# [roo_backport 1.1.1](https://github.com/dejwk/roo_backport/releases/tag/1.1.1)

Published 2025-10-30.

Added a .gitignore file.

---

# [roo_backport 1.1.0](https://github.com/dejwk/roo_backport/releases/tag/1.1.0)

Published 2025-08-09.

Making roo_backport a Bazel module, to make it easier to use in unit tests of depending libraries.

---

# [roo_backport 1.0.2](https://github.com/dejwk/roo_backport/releases/tag/1.0.2)

Published 2025-07-04.

Added backport for std::move.

---

# [roo_backport 1.0.1](https://github.com/dejwk/roo_backport/releases/tag/1.0.1)

Published 2025-01-27.

Initial release.

---

