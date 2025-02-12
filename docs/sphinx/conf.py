import shutil
from cgitb import html
from datetime import date
from glob import glob

project = "Snake"
package = "snake"
version = "0.3.3"

project_copyright = f"{date.today().year} Joel Lefkowitz"

extensions = [
    "breathe",
    "myst_parser",
    "sphinxext.opengraph",
    "sphinx.ext.graphviz",
]

myst_all_links_external = True

breathe_default_project = project

breathe_projects = {
    project: "../doxygen/dist",
}

breathe_default_members = (
    "members",
    "private-members",
    "protected-members",
    "undoc-members",
    "allow-dot-graphs",
)

theme = {
    "color-problematic": "#4165FF",
    "color-brand-content": "#4165FF",
    "color-brand-primary": "#914FF5",
    "font-stack": "Space Grotesk, sans-serif",
    "font-stack--monospace": "CQ Mono, monospace",
}

html_theme = "furo"
html_title = project
html_static_path = [""]
html_js_files = ["scripts.js"]
html_css_files = ["styles.css"]
html_theme_options = {
    "light_css_variables": {
        **theme,
        "color-highlight-on-target": "#E0E0E0",
    },
    "dark_css_variables": {
        **theme,
        "color-highlight-on-target": "#202020",
    },
}


def filter_inputs(app, build):
    for pattern in ["docs/**/*std.rst", "docs/**/file/*[c,t]pp.rst"]:
        for path in glob(pattern, recursive=True):
            os.remove(path)

    for path in glob("docs/**/class/*.rst", recursive=True):
        with open(path, "a") as stream:
            stream.write(" " * 3 + ":allow-dot-graphs:\n")


def copy_static(app, build):
    shutil.copytree("docs/images", "docs/dist/docs/images", dirs_exist_ok=True)

    for path in glob("*.md"):
        shutil.copyfile(path, f"docs/dist/{path}")


def setup(app):
    app.connect("config-inited", filter_inputs)
    app.connect("build-finished", copy_static)
