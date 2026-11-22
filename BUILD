# BUILD file for use with https://github.com/dejwk/roo_testing.

load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_cc//cc:cc_test.bzl", "cc_test")

cc_library(
    name = "roo_backport",
    hdrs = glob(["src/**/*.h"]),
    includes = [
        "src",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "backport_cxx11_test",
    size = "small",
    srcs = ["test/backport_test.cpp"],
    copts = ["-std=c++11"],
    deps = [":roo_backport"],
)

cc_test(
    name = "backport_cxx17_test",
    size = "small",
    srcs = ["test/backport_test.cpp"],
    copts = ["-std=c++17"],
    deps = [":roo_backport"],
)

cc_test(
    name = "backport_cxx11_portable_bitops_test",
    size = "small",
    srcs = ["test/backport_test.cpp"],
    copts = ["-std=c++11"],
    local_defines = ["ROO_BACKPORT_HAS_BUILTIN_CTZ=0"],
    deps = [":roo_backport"],
)

cc_test(
    name = "backport_cxx20_test",
    size = "small",
    srcs = ["test/backport_test.cpp"],
    copts = ["-std=c++20"],
    deps = [":roo_backport"],
)
