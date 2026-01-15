{
  mkShell,
  config,
  bashInteractive,
  clang-tools,
  cmake,
  cppcheck,
  fd,
  gum,
  just,
  neocmakelsp,
  ninja,
  openssl,
  pkg-config,
}:
mkShell {
  name = "default";
  inputsFrom = [
    config.treefmt.build.devShell
  ];
  packages = [
    bashInteractive
    clang-tools
    cmake
    cppcheck
    fd
    gum
    just
    neocmakelsp
    ninja
    openssl
    pkg-config
  ];
}
