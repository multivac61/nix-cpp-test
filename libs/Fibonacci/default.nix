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
    "-DPOAC_BUILD_TESTING=OFF"
    "-DCPM_SOURCE_CACHE=${placeholder "out"}/share"
    "-DFETCHCONTENT_SOURCE_DIR_PACKAGEPROJECT.CMAKE=${pkgs.package-project-cmake.src}"
  ];
}
