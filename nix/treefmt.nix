{
  projectRootFile = "flake.nix";
  programs = {
    clang-format.enable = true;
    deadnix.enable = true;
    just.enable = true;
    keep-sorted.enable = true;
    mdformat.enable = true;
    nixfmt.enable = true;
    statix.enable = true;
  };
}
