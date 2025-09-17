#ifndef COMMON_H
#define COMMON_H

#include <QScopedPointer>
#include <QStylePainter>
#include <QtGlobal>

#ifdef QSK_LIBRARY_BUILD
#  define QSK_LIBRARY Q_DECL_EXPORT
#else
#  define QSK_LIBRARY Q_DECL_IMPORT
#endif

#define QSK_NAMESPACE_BEGIN namespace QSK {
#define QSK_NAMESPACE_END }

#define QSK_DECLARE_DPTR_PRIVATE(ClassName) \
    Q_DISABLE_COPY(ClassName)  \
    Q_DECLARE_PRIVATE(ClassName) \
    QScopedPointer<ClassName##Private> d_ptr;

#define QSK_DECLARE_DPTR_PUBLIC(ClassName) \
    ClassName *q_ptr;               \
    Q_DECLARE_PUBLIC(ClassName)

// #define QSK_PROPERTY(type, name) \
//     Q_PROPERTY(type name READ name WRITE set##name NOTIFY name##Changed FINAL)

#define QSK_PROPERTY(type, name, defaultValue)                 \
private:                                                       \
    Q_PROPERTY(type name READ name WRITE set##name NOTIFY name##Changed FINAL)\
    type m_##name = defaultValue;                              \
public:                                                        \
    inline type name() const { return m_##name; }              \
    inline void set##name(type value) {                        \
        if (m_##name != value) {                               \
            m_##name = value;                                  \
            emit name##Changed(value);                         \
        }                                                      \
    }                                                          \
Q_SIGNALS:                                                     \
    void name##Changed(type);

#define QSK_PROPERTY_DEFINE(type, name)                 \
private:                                                       \
    Q_PROPERTY(type name READ name WRITE set##name)\
public:                                                        \
    type name() const;              \
    void set##name(type value);


#define QSK_HEX_TO_DEC(c) \
    ((c >= '0' && c <= '9') ? (c - '0') : \
    (c >= 'a' && c <= 'f') ? (c - 'a' + 10) : \
    (c - 'A' + 10))

#define QSK_QRGB_LITERAL(str) qRgb( \
    (QSK_HEX_TO_DEC(str[1]) << 4) + QSK_HEX_TO_DEC(str[2]), \
    (QSK_HEX_TO_DEC(str[3]) << 4) + QSK_HEX_TO_DEC(str[4]), \
    (QSK_HEX_TO_DEC(str[5]) << 4) + QSK_HEX_TO_DEC(str[6])  \
)

#endif // COMMON_H
