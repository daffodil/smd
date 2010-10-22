
#include "importwizard.h"
#include "importwizzselectmodepage.h"


ImportWizard::ImportWizard(QWidget *parent) :
    QWizard(parent)
{
    setWindowTitle("Import Wizard");

    addPage(new ImportWizzSelectModePage());
}
