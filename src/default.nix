{ stdenv, pkgs, ... }:

stdenv.mkDerivation {
  name = "Fibonacci-consumer";
  src = ./.;
  doCheck = true;

  nativeBuildInputs = with pkgs; [
    clang
    cmake
    ninja
    ut
    nlohmann_json
    (pkgs.callPackage ../libs/Fibonacci { })
  ];
}
