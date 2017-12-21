#ifndef QBGUILIB_GLOBAL_H
#define QBGUILIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QBGUILIB_LIBRARY)
#  define QBGUILIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QBGUILIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QBGUILIB_GLOBAL_H
