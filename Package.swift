// swift-tools-version: 5.9

import PackageDescription

let package = Package(
    name: "YGOProCore",
    products: [
        .library(
            name: "CLua",
            type: .static,
            targets: ["CLua"]
        ),
        .library(
            name: "YGOProCore",
            type: .static,
            targets: ["YGOProCore"]
        ),
    ],
    targets: [
        .target(
            name: "CLua",
            exclude: ["lua.c", "luac.c"]
        ),
        .target(
            name: "YGOProCoreCxx",
            dependencies: ["CLua"]
        ),
        .target(
            name: "YGOProCore",
            dependencies: ["YGOProCoreCxx"],
            swiftSettings: [.interoperabilityMode(.Cxx)]
        ),
        .executableTarget(
            name: "YGOProCoreExample",
            dependencies: ["YGOProCore", "CLua"],
            swiftSettings: [.interoperabilityMode(.Cxx)]
        ),
        .testTarget(
            name: "YGOProCoreTests",
            dependencies: ["YGOProCore"],
            swiftSettings: [.interoperabilityMode(.Cxx)]
        ),
    ],
    cxxLanguageStandard: .gnucxx20
)
