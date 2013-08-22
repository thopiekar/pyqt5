// This is the definition of the QPyQmlObject classes.
//
// Copyright (c) 2013 Riverbank Computing Limited <info@riverbankcomputing.com>
// 
// This file is part of PyQt5.
// 
// This file may be used under the terms of the GNU General Public License
// version 3.0 as published by the Free Software Foundation and appearing in
// the file LICENSE included in the packaging of this file.  Please review the
// following information to ensure the GNU General Public License version 3.0
// requirements will be met: http://www.gnu.org/copyleft/gpl.html.
// 
// If you do not wish to use this file under the terms of the GPL version 3.0
// then you may purchase a commercial license.  For more information contact
// info@riverbankcomputing.com.
// 
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.


#ifndef _QPYQMLOBJECT_H
#define _QPYQMLOBJECT_H


#include <Python.h>

#include <QList>
#include <QObject>
#include <QPointer>
#include <QQmlParserStatus>
#include <QQmlProperty>
#include <QQmlPropertyValueSource>
#include <QSet>


class QPyQmlObjectProxy : public QObject
{
public:
    QPyQmlObjectProxy(QObject *parent = 0);
    virtual ~QPyQmlObjectProxy();

    virtual const QMetaObject *metaObject() const;
    virtual void *qt_metacast(const char *_clname);
    virtual int qt_metacall(QMetaObject::Call, int, void **);

    virtual int typeNr() const = 0;

    static int addType(PyTypeObject *type);
    void createPyObject(QObject *parent);

    static QObject *createAttachedProperties(PyTypeObject *py_type,
            QObject *parent);

    static void *resolveProxy(void *proxy);

    void pyClassBegin();
    void pyComponentComplete();

    void pySetTarget(const QQmlProperty &target);

    // The set of proxies in existence.
    static QSet<QObject *> proxies;

    // A reference to the real object.
    QPointer<QObject> proxied;

protected:
    void connectNotify(const QMetaMethod &signal);
    void disconnectNotify(const QMetaMethod &signal);

private:
    // These can by cast to sipWrapperType and pyqtWrapperType.
    static QList<PyTypeObject *> pyqt_types;

    // The wrapped proxied object.
    PyObject *py_proxied;

    static QByteArray signalSignature(const QMetaMethod &signal);

    QPyQmlObjectProxy(const QPyQmlObjectProxy &);
};


// The proxy type declarations.
#define QPYQML_PROXY_DECL(n) \
class QPyQmlObject##n : public QPyQmlObjectProxy, public QQmlParserStatus, public QQmlPropertyValueSource  \
{ \
public: \
    QPyQmlObject##n(QObject *parent = 0); \
    static QMetaObject staticMetaObject; \
    virtual int typeNr() const {return n##U;} \
    static PyTypeObject *attachedPyType; \
    static QObject *attachedProperties(QObject *parent); \
    virtual void classBegin(); \
    virtual void componentComplete(); \
    virtual void setTarget(const QQmlProperty &target); \
private: \
    QPyQmlObject##n(const QPyQmlObject##n &); \
}


QPYQML_PROXY_DECL(0);
QPYQML_PROXY_DECL(1);
QPYQML_PROXY_DECL(2);
QPYQML_PROXY_DECL(3);
QPYQML_PROXY_DECL(4);
QPYQML_PROXY_DECL(5);
QPYQML_PROXY_DECL(6);
QPYQML_PROXY_DECL(7);
QPYQML_PROXY_DECL(8);
QPYQML_PROXY_DECL(9);
QPYQML_PROXY_DECL(10);
QPYQML_PROXY_DECL(11);
QPYQML_PROXY_DECL(12);
QPYQML_PROXY_DECL(13);
QPYQML_PROXY_DECL(14);
QPYQML_PROXY_DECL(15);
QPYQML_PROXY_DECL(16);
QPYQML_PROXY_DECL(17);
QPYQML_PROXY_DECL(18);
QPYQML_PROXY_DECL(19);


#endif
