{
  description = "Application packaged using poetry2nix";

  nixConfig = {
    extra-substituters = [
      "https://ros.cachix.org"
      "https://nix-community.cachix.org"
      "https://genki.cachix.org"
    ];
    extra-trusted-public-keys = [
      "ros.cachix.org-1:dSyZxI8geDCJrwgvCOHDoAfOm5sV1wCPjBkKL+38Rvo="
      "nix-community.cachix.org-1:mB9FSh9qf2dCimDSUo8Zy7bkq5CX+/rkCWyvRCYg3Fs="
      "genki.cachix.org-1:5l+wAa4rDwhcd5Wm43eK4N73qJ6GIKmJQ87Nw/bRGfE="
    ];
  };

  inputs = {
    flake-parts.url = "github:hercules-ci/flake-parts";
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable-small";
    poetry2nix = {
      url = "github:nix-community/poetry2nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
    devshell.url = "github:numtide/devshell";
  };

  outputs = { self, nixpkgs, flake-parts, poetry2nix, devshell }@inputs:
    flake-parts.lib.mkFlake { inherit inputs; } {
      imports = [ devshell.flakeModule ];

      systems = [ "x86_64-linux" "aarch64-darwin" ];

      perSystem = { pkgs, system, ... }:
        {
          packages.default = pkgs.callPackage ./libs/Fibonacci { };
          devshells.default = {
            packages = [
              pkgs.poetry

              pkgs.clang
              pkgs.cmake
              pkgs.ninja

              pkgs.ut
              pkgs.nlohmann_json
            ];
            env = [
              # {
              #   name = "CMAKE_KITS";
              #   # https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/kits.md#project-kits
              #   # To define a project-local kit, create a .vscode/cmake-kits.json file in the project directory.
              #   eval = /* bash */ ''$(mkdir -p .vscode; echo '[{ "name": "My Clang", "compilers": { "C": "${pkgs.clang}/bin/clang", "CXX": "${pkgs.clang}/bin/clang++" }, "isTrusted": true }]' > .vscode/cmake-kits.json; echo ".vscode/cmake-kits.json")'';
              # }
            ];
          };
        };
    };
}

