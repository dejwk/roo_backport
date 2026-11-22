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
