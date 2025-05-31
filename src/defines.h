#ifndef DEFINES_H
#define DEFINES_H

/**
 * @file defines.h
 * @brief Cross-platform macros for linkage, visibility, inlining, and attributes.
 */

// ─────────────────────────────────────────────
// Semantic And Visibility Macros
// ─────────────────────────────────────────────

/**
 * @def PRIVATE
 * @brief Marks a symbol as internal to the translation unit (and hidden, if supported).
 */
#if defined(__GNUC__) || defined(__clang__)
    #define PRIVATE static __attribute__((visibility("hidden")))
#else
    #define PRIVATE static
#endif

/**
 * @def INTERNAL
 * @brief Alias for `static`. Indicates internal linkage.
 */
#define INTERNAL static

/**
 * @def EXTERNAL
 * @brief Declares an external symbol (global variable or function).
 */
#define EXTERNAL extern

/**
 * @def PUBLIC
 * @brief Optional semantic marker for public-facing functions or variables.
 */
#define PUBLIC

// ─────────────────────────────────────────────
// Inlining And Optimization Macros
// ─────────────────────────────────────────────

/**
 * @def INLINE
 * @brief Suggests that a function should be inlined.
 */
#define INLINE inline

/**
 * @def FORCE_INLINE
 * @brief Forces the compiler to inline the function if possible.
 */
#if defined(__GNUC__) || defined(__clang__)
    #define FORCE_INLINE __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
    #define FORCE_INLINE __forceinline
#else
    #define FORCE_INLINE inline
#endif

/**
 * @def HELPER
 * @brief Marks a static inline helper function.
 */
#define HELPER static INLINE

/**
 * @def PRE_MAIN
 * @brief Executes a function before `main()` (if supported).
 */
#if defined(__GNUC__) || defined(__clang__)
    #define PRE_MAIN __attribute__((constructor))
#else
    #define PRE_MAIN
#endif

/**
 * @def POST_MAIN
 * @brief Executes a function after `main()` returns (if supported).
 */
#if defined(__GNUC__) || defined(__clang__)
    #define POST_MAIN __attribute__((destructor))
#else
    #define POST_MAIN
#endif

// ─────────────────────────────────────────────
// Export / Visibility Macros For Shared Libraries
// ─────────────────────────────────────────────

/**
 * @def API_EXPORT
 * @brief Exports a symbol from a shared library.
 */
#if defined(_WIN32) || defined(_WIN64)
    #define API_EXPORT __declspec(dllexport)
#else
    #if defined(__GNUC__) && __GNUC__ >= 4
        #define API_EXPORT __attribute__((visibility("default")))
    #else
        #define API_EXPORT
    #endif
#endif

/**
 * @def TGAPI
 * @brief Public API export macro. Defined only when EXPORT_ENABLED and BUILD_SHARED are set.
 */
#if defined(EXPORT_ENABLED) && defined(BUILD_SHARED)
    #define TGAPI API_EXPORT
#else
    #define TGAPI
#endif

// ─────────────────────────────────────────────
// Utility Attribute Macros
// ─────────────────────────────────────────────

/**
 * @def UNUSED(x)
 * @brief Silences warnings for unused variables.
 */
#define UNUSED(x) ((void)(x))

/**
 * @def DEPRECATED
 * @brief Marks a symbol as deprecated.
 */
#if defined(__GNUC__) || defined(__clang__)
    #define DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
    #define DEPRECATED __declspec(deprecated)
#else
    #define DEPRECATED
#endif

/**
 * @def ALIGN(N)
 * @brief Aligns a variable or struct to N-byte boundary.
 */
#if defined(__GNUC__) || defined(__clang__)
    #define ALIGN(N) __attribute__((aligned(N)))
#elif defined(_MSC_VER)
    #define ALIGN(N) __declspec(align(N))
#else
    #define ALIGN(N)
#endif

/**
 * @def PACKED
 * @brief Removes padding from a struct.
 */
#if defined(__GNUC__) || defined(__clang__)
    #define PACKED __attribute__((packed))
#elif defined(_MSC_VER)
    #define PACKED
#else
    #define PACKED
#endif

#endif // DEFINES_H
