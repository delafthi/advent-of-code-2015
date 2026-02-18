{
  mkShell,
  cmake,
  cppcheck,
  gum,
  neocmakelsp,
  ninja,
  openssl,
  pkg-config,
  config,
}:
mkShell {
  name = "advent-of-code-2015";
  inputsFrom = [
    config.treefmt.build.devShell
  ];
  packages = [
    cmake
    cppcheck
    gum
    neocmakelsp
    ninja
    openssl
    pkg-config
  ];
}
