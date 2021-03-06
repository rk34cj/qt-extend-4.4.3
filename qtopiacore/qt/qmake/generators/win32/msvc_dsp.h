/****************************************************************************
**
** Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the qmake application of the Qt Toolkit.
**
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License versions 2.0 or 3.0 as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file.  Please review the following information
** to ensure GNU General Public Licensing requirements will be met:
** http://www.fsf.org/licensing/licenses/info/GPLv2.html and
** http://www.gnu.org/copyleft/gpl.html.  In addition, as a special
** exception, Nokia gives you certain additional rights. These rights
** are described in the Nokia Qt GPL Exception version 1.3, included in
** the file GPL_EXCEPTION.txt in this package.
**
** Qt for Windows(R) Licensees
** As a special exception, Nokia, as the sole copyright holder for Qt
** Designer, grants users of the Qt/Eclipse Integration plug-in the
** right for the Qt/Eclipse Integration to link to functionality
** provided by Qt Designer and its related libraries.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
**
****************************************************************************/

#ifndef MSVC_DSP_H
#define MSVC_DSP_H

#include "winmakefile.h"

QT_BEGIN_NAMESPACE

class FolderGroup;

class DspMakefileGenerator : public Win32MakefileGenerator
{
    bool init_flag;
    bool writeDspHeader(QTextStream &);
    bool writeDspParts(QTextStream &);
    bool writeFileGroup(QTextStream &t, const QStringList &listNames, const QString &group, const QString &filter);
    void writeSubFileGroup(QTextStream &t, FolderGroup *folder);
    bool writeBuildstepForFile(QTextStream &t, const QString &file, const QString &listName);
    static bool writeDspConfig(QTextStream &t, DspMakefileGenerator *config);
    static QString writeBuildstepForFileForConfig(const QString &file, const QString &listName, DspMakefileGenerator *config);
    QString configName(DspMakefileGenerator * config);

    bool writeMakefile(QTextStream &);
    bool writeProjectMakefile();
    void writeSubDirs(QTextStream &t);
    void init();

public:
    DspMakefileGenerator();
    ~DspMakefileGenerator();

    bool openOutput(QFile &file, const QString &build) const;
    bool hasBuiltinCompiler(const QString &filename) const;

protected:
    virtual bool doDepends() const { return false; } //never necesary
    virtual void processSources() { filterIncludedFiles("SOURCES"); filterIncludedFiles("GENERATED_SOURCES"); }
    virtual QString replaceExtraCompilerVariables(const QString &, const QStringList &, const QStringList &);
    inline QString replaceExtraCompilerVariables(const QString &val, const QString &in, const QString &out)
    { return MakefileGenerator::replaceExtraCompilerVariables(val, in, out); }
    virtual bool supportsMetaBuild() { return true; }
    virtual bool supportsMergedBuilds() { return true; }
    virtual bool mergeBuildProject(MakefileGenerator *other);
    virtual void processPrlVariable(const QString &, const QStringList &);
    virtual bool findLibraries();

    bool usePCH;
    QString precompH, namePCH,
            precompObj, precompPch;

    QString platform;

    struct BuildStep {
        BuildStep() {}
        BuildStep &operator<<(const BuildStep &other) {
            deps << other.deps;
            buildStep += other.buildStep;
            buildName += other.buildName;
            buildOutputs += other.buildOutputs;
            return *this;
        }

        QStringList deps;
        QString buildStep;
        QString buildName;
        QStringList buildOutputs;
    };
    QMap<QString, BuildStep> swappedBuildSteps;

    // Holds all configurations for glue (merged) project
    QList<DspMakefileGenerator*> mergedProjects;
};

inline DspMakefileGenerator::~DspMakefileGenerator()
{ }

inline bool DspMakefileGenerator::findLibraries()
{ return Win32MakefileGenerator::findLibraries("MSVCDSP_LIBS"); }

QT_END_NAMESPACE

#endif // MSVC_DSP_H
