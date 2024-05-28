{ pkgs ? import <nixpkgs> { } }:

pkgs.clangStdenv.mkDerivation {
  name = "Fibonacci-consumer";
  src = ./.;

  nativeBuildInputs = with pkgs; [
    clang
    cmake
    ninja
    ut
    nlohmann_json
    (callPackage ../libs/Fibonacci { })
  ];
}