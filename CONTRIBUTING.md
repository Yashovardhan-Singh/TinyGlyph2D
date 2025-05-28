# Contributing to TinyGlyph2D

Thank you for your interest in contributing to **TinyGlyph2D**! We welcome contributions of all kinds, including bug  
reports, feature requests, documentation improvements, and code enhancements.

---

## 🚀 Getting Started

1. **Fork the Repository**: Click the Fork button on the top right of the repository page.
2. **Clone Your Fork**:

   ```bash
   git clone https://github.com/Yashovardhan-Singh/TinyGlyph2D.git
   cd TinyGlyph2D
   ```
3. **Create a New Branch**:

   ```bash
   git checkout -b your-feature-name
   ```

---

## 🛠 Building the Project

This project uses [Meson](https://mesonbuild.com/) as the build system.

1. **Set up the build directory**:

   ```bash
   meson setup build
   ```
2. **Build the project**:

   ```bash
   meson compile -C build
   ```
3. **Run examples or tests** (if available):

   ```bash
   ./build/example
   ```

Make sure you have required dependencies installed such as `meson`, `ninja`, and development libraries like `glfw`.

---

## 📏 Conventions/Guidelines

See [CONVENTIONS.md](CONVENTIONS.md) for code guidelines

---

## 📋 Commit Guidelines

* Use clear, concise commit messages.
* Follow the format:

  ```
  type(scope): subject

  body (optional)
  ```
* Example:

  ```
  feat(renderer): add batching support for draw calls
  ```

---

## 🧪 Testing

* Add or update tests for your changes if applicable.
* Make sure all tests pass before submitting a pull request.

---

## 🔁 Submitting a Pull Request

1. Push your branch:

   ```bash
   git push origin your-feature-name
   ```
2. Open a pull request on GitHub.
3. Fill out the PR template, explaining what you changed and why.

---

## 🤝 Code of Conduct

Be respectful, inclusive, and considerate.

---

## 📬 Contact

For major issues or questions, please open a [GitHub Issue](https://github.com/Yashovardhan-Singh/TinyGlyph2D/issues)  
or contact the maintainers directly.

---

Happy coding! 💻
