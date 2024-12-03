# Configuration file for the Sphinx documentation builder.

# -- Project information -----------------------------------------------------
project = "Alien Invasion"
copyright = "2024, Daniel Mora"
author = "Daniel Mora"
release = "1.0"

# -- General configuration ---------------------------------------------------
extensions = [
    "breathe",
    "sphinx.ext.autodoc",       # Optional: For Python docstrings if needed
    "sphinx.ext.napoleon",      # Optional: For Google/NumPy style docstrings
    "sphinx.ext.viewcode"       # Optional: For source code links
]

templates_path = ["_templates"]
exclude_patterns = []

# -- Options for Breathe and Doxygen -----------------------------------------
import os
breathe_projects = {
    "Alien Invasion": "../doxygen/xml"  # Path to Doxygen XML files
}
breathe_default_project = "Alien Invasion"

# Ensure you run Doxygen with XML generation enabled to populate ../doxygen/xml.

# -- Options for HTML output -------------------------------------------------
html_theme = "alabaster"  # You can change this to 'sphinx_rtd_theme' or others.
html_static_path = ["_static"]

# -- Add custom CSS for better formatting (Optional) -------------------------

