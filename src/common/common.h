#ifndef COMMON_H
#define COMMON_H

#include <QScopedPointer>
#include <QtGlobal>

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
    type name() const { return m_##name; }                    \
    void set##name(type value) {                               \
        if (m_##name != value) {                               \
            m_##name = value;                                  \
            emit name##Changed(value);                         \
        }                                                      \
    }                                                          \
Q_SIGNALS:                                                     \
    void name##Changed(type);


#endif // COMMON_H
