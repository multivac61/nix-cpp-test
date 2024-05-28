{ stdenv, pkgs, ... }:

stdenv.mkDerivation {
  name = "Fibonacci";
  src = ./.;
  doCheck = true;

  nativeBuildInputs = with pkgs; [
    clang
    cmake
    ninja
    ut
    package-project-cmake
  ];

  cmakeFlags = [
    "-DFETCHCONTENT_FULLY_DISCONNECTED=ON"
    "-DFETCHCONTENT_SOURCE_DIR_PACKAGEPROJECT.CMAKE=${pkgs.package-project-cmake.src}"
  ];
}
