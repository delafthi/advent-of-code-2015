{
  projectRootFile = "flake.nix";
  programs = {
    clang-format.enable = true;
    cmake-format.enable = true;
    deadnix.enable = true;
    just.enable = true;
    keep-sorted.enable = true;
    nixfmt.enable = true;
    rumdl-check.enable = true;
    statix.enable = true;
  };
}
