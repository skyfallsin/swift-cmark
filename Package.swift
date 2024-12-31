// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

#if os(Windows)
    let cSettings: [CSetting] = [
        .define("CMARK_GFM_STATIC_DEFINE", .when(platforms: [.windows])),
        .define("CMARK_THREADING"),
    ]
#else
    let cSettings: [CSetting] = [
        .define("CMARK_THREADING"),
        .define("CMARK_STATIC_DEFINE"),
    ]
#endif

let cxxSettings: [CXXSetting] = [
    .headerSearchPath("../src/include"),
    .headerSearchPath("../extensions/include"),
    .unsafeFlags(["-std=c++11", "-x", "c++"])
]

let package = Package(
    name: "cmark-gfm",
    products: [
        .library(
            name: "cmark-gfm",
            type: .static,
            targets: ["cmark-gfm"]),
        .library(
            name: "cmark-gfm-extensions",
            type: .static,
            targets: ["cmark-gfm-extensions"]),
        .executable(
            name: "cmark-gfm-bin",
            targets: ["cmark-gfm-bin"]),
        .executable(name: "api_test",
            targets: ["api_test"])
    ],
    targets: [
        .target(name: "cmark-gfm",
          path: "src",
          exclude: [
            "scanners.re",
            "libcmark-gfm.pc.in",
            "CMakeLists.txt",
          ],
          sources: [
            "arena.c",
            "blocks.c",
            "buffer.c",
            "cmark.c",
            "cmark_ctype.c",
            "commonmark.c",
            "footnotes.c",
            "houdini_href_e.c",
            "houdini_html_e.c",
            "houdini_html_u.c",
            "html.c",
            "inlines.c",
            "iterator.c",
            "latex.c",
            "linked_list.c",
            "man.c",
            "map.c",
            "node.c",
            "plaintext.c",
            "plugin.c",
            "references.c",
            "registry.c",
            "render.c",
            "scanners.c",
            "syntax_extension.c",
            "utf8.c",
            "xml.c",
          ],
          cSettings: cSettings + [
            .headerSearchPath("include"),
            .headerSearchPath("."),
            .unsafeFlags(["-x", "c"])
          ]
        ),
        .target(name: "cmark-gfm-extensions",
          dependencies: [
            "cmark-gfm",
          ],
          path: "extensions",
          exclude: [
            "CMakeLists.txt",
            "ext_scanners.re",
          ],
          sources: [
            "autolink.c",
            "core-extensions.c",
            "strikethrough.c",
            "table.c",
            "tagfilter.c",
            "tasklist.c",
            "ext_scanners.c",
          ],
          cSettings: cSettings + [
            .headerSearchPath("../src/include"),
            .headerSearchPath("include"),
            .headerSearchPath("."),
            .unsafeFlags(["-x", "c"])
          ]
        ),
        .target(name: "cmark-gfm-bin",
          dependencies: [
            "cmark-gfm",
            "cmark-gfm-extensions",
          ],
          path: "bin",
          sources: [
            "main.c",
          ],
          cSettings: cSettings + [
            .headerSearchPath("../src/include"),
            .headerSearchPath("../extensions/include"),
            .unsafeFlags(["-x", "c"])
          ]
        ),
        .target(name: "api_test",
          dependencies: [
            "cmark-gfm",
            "cmark-gfm-extensions",
          ],
          path: "api_test",
          exclude: [
            "CMakeLists.txt",
          ],
          cSettings: cSettings + [
            .headerSearchPath("../src/include"),
            .headerSearchPath("../extensions/include"),
            .unsafeFlags(["-x", "c"])
          ],
          cxxSettings: cxxSettings
        )
    ]
)
