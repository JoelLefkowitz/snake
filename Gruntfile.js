module.exports = function (grunt) {
  grunt.initConfig({
    exec: {
      astyle: "make format",
      cspell: "npx cspell -c .cspell.json {*,.*,**/*}",
      prettier: "prettier . --write",
      quickdocs: "quickdocs .quickdocs.yml",
      remark: "npx remark -r .remarkrc .",
      sphinx: "sphinx-build docs build",
    },
  });

  grunt.loadNpmTasks("grunt-exec");

  grunt.registerTask(
    "lint",
    "Lint the source code",
    ["cspell", "remark"].map((i) => "exec:".concat(i))
  );

  grunt.registerTask(
    "format",
    "Format the source code",
    ["prettier", "astyle"].map((i) => "exec:".concat(i))
  );

  grunt.registerTask(
    "docs:generate",
    "Generate a Sphinx documentation configuration",
    "exec:quickdocs"
  );

  grunt.registerTask(
    "docs:build",
    "Build documentation from a Sphinx configuration",
    "exec:sphinx"
  );

  grunt.registerTask(
    "precommit",
    "Run a sequence of precommit quality control tasks",
    ["lint", "tests:unit", "docs:generate"]
  );

  grunt.registerTask("tests:unit", "Run unit tests", () =>
    console.log("No unit tests")
  );
};
