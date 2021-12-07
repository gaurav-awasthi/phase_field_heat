#include "PhaseFieldHeatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
PhaseFieldHeatApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

PhaseFieldHeatApp::PhaseFieldHeatApp(InputParameters parameters) : MooseApp(parameters)
{
  PhaseFieldHeatApp::registerAll(_factory, _action_factory, _syntax);
}

PhaseFieldHeatApp::~PhaseFieldHeatApp() {}

void
PhaseFieldHeatApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"PhaseFieldHeatApp"});
  Registry::registerActionsTo(af, {"PhaseFieldHeatApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
PhaseFieldHeatApp::registerApps()
{
  registerApp(PhaseFieldHeatApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
PhaseFieldHeatApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  PhaseFieldHeatApp::registerAll(f, af, s);
}
extern "C" void
PhaseFieldHeatApp__registerApps()
{
  PhaseFieldHeatApp::registerApps();
}
