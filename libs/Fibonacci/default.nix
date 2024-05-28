{ stdenv, pkgs, ... }:

stdenv.mkDerivation {
  name = "Fibonacci";
  src = ./.;

  nativeBuildInputs = with pkgs; [
    clang
    cmake
    ninja
    ut
  ];
}
