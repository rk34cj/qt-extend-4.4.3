/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#include "JSHTMLHeadingElement.h"

#include <wtf/GetPtr.h>

#include "HTMLHeadingElement.h"
#include "PlatformString.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashEntry JSHTMLHeadingElementTableEntries[] =
{
    { 0, 0, 0, 0, 0 },
    { "align", JSHTMLHeadingElement::AlignAttrNum, DontDelete, 0, &JSHTMLHeadingElementTableEntries[2] },
    { "constructor", JSHTMLHeadingElement::ConstructorAttrNum, DontDelete|DontEnum|ReadOnly, 0, 0 }
};

static const HashTable JSHTMLHeadingElementTable = 
{
    2, 3, JSHTMLHeadingElementTableEntries, 2
};

/* Hash table for constructor */

static const HashEntry JSHTMLHeadingElementConstructorTableEntries[] =
{
    { 0, 0, 0, 0, 0 }
};

static const HashTable JSHTMLHeadingElementConstructorTable = 
{
    2, 1, JSHTMLHeadingElementConstructorTableEntries, 1
};

class JSHTMLHeadingElementConstructor : public DOMObject {
public:
    JSHTMLHeadingElementConstructor(ExecState* exec)
    {
        setPrototype(exec->lexicalInterpreter()->builtinObjectPrototype());
        putDirect(exec->propertyNames().prototype, JSHTMLHeadingElementPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &info; }
    static const ClassInfo info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSHTMLHeadingElementConstructor::info = { "HTMLHeadingElementConstructor", 0, &JSHTMLHeadingElementConstructorTable, 0 };

bool JSHTMLHeadingElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLHeadingElementConstructor, DOMObject>(exec, &JSHTMLHeadingElementConstructorTable, this, propertyName, slot);
}

JSValue* JSHTMLHeadingElementConstructor::getValueProperty(ExecState*, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(token);
}

/* Hash table for prototype */

static const HashEntry JSHTMLHeadingElementPrototypeTableEntries[] =
{
    { 0, 0, 0, 0, 0 }
};

static const HashTable JSHTMLHeadingElementPrototypeTable = 
{
    2, 1, JSHTMLHeadingElementPrototypeTableEntries, 1
};

const ClassInfo JSHTMLHeadingElementPrototype::info = { "HTMLHeadingElementPrototype", 0, &JSHTMLHeadingElementPrototypeTable, 0 };

JSObject* JSHTMLHeadingElementPrototype::self(ExecState* exec)
{
    return KJS::cacheGlobalObject<JSHTMLHeadingElementPrototype>(exec, "[[JSHTMLHeadingElement.prototype]]");
}

const ClassInfo JSHTMLHeadingElement::info = { "HTMLHeadingElement", &JSHTMLElement::info, &JSHTMLHeadingElementTable, 0 };

JSHTMLHeadingElement::JSHTMLHeadingElement(ExecState* exec, HTMLHeadingElement* impl)
    : JSHTMLElement(exec, impl)
{
    setPrototype(JSHTMLHeadingElementPrototype::self(exec));
}

bool JSHTMLHeadingElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLHeadingElement, JSHTMLElement>(exec, &JSHTMLHeadingElementTable, this, propertyName, slot);
}

JSValue* JSHTMLHeadingElement::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case AlignAttrNum: {
        HTMLHeadingElement* imp = static_cast<HTMLHeadingElement*>(impl());

        return jsString(imp->align());
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

void JSHTMLHeadingElement::put(ExecState* exec, const Identifier& propertyName, JSValue* value, int attr)
{
    lookupPut<JSHTMLHeadingElement, JSHTMLElement>(exec, propertyName, value, attr, &JSHTMLHeadingElementTable, this);
}

void JSHTMLHeadingElement::putValueProperty(ExecState* exec, int token, JSValue* value, int /*attr*/)
{
    switch (token) {
    case AlignAttrNum: {
        HTMLHeadingElement* imp = static_cast<HTMLHeadingElement*>(impl());

        imp->setAlign(valueToStringWithNullCheck(exec, value));
        break;
    }
    }
}

JSValue* JSHTMLHeadingElement::getConstructor(ExecState* exec)
{
    return KJS::cacheGlobalObject<JSHTMLHeadingElementConstructor>(exec, "[[HTMLHeadingElement.constructor]]");
}

}