# BUILD file for use with https://github.com/dejwk/roo_testing.

load("@rules_cc//cc:cc_library.bzl", "cc_library")

cc_library(
    name = "roo_backport",
    srcs = glob(
        [
            "src/**/*.h",
        ],
    ),
    includes = [
        "src",
    ],
    visibility = ["//visibility:public"],
)
