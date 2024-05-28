{ pkgs ? import <nixpkgs> { } }:

pkgs.clangStdenv.mkDerivation {
  name = "Fibonacci";
  src = ./.;

  nativeBuildInputs = with pkgs; [
    clang
    cmake
    ninja
  ];
}
