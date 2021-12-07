//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "PhaseFieldHeatTestApp.h"
#include "PhaseFieldHeatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
PhaseFieldHeatTestApp::validParams()
{
  InputParameters params = PhaseFieldHeatApp::validParams();
  return params;
}

PhaseFieldHeatTestApp::PhaseFieldHeatTestApp(InputParameters parameters) : MooseApp(parameters)
{
  PhaseFieldHeatTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

PhaseFieldHeatTestApp::~PhaseFieldHeatTestApp() {}

void
PhaseFieldHeatTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  PhaseFieldHeatApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"PhaseFieldHeatTestApp"});
    Registry::registerActionsTo(af, {"PhaseFieldHeatTestApp"});
  }
}

void
PhaseFieldHeatTestApp::registerApps()
{
  registerApp(PhaseFieldHeatApp);
  registerApp(PhaseFieldHeatTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
PhaseFieldHeatTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  PhaseFieldHeatTestApp::registerAll(f, af, s);
}
extern "C" void
PhaseFieldHeatTestApp__registerApps()
{
  PhaseFieldHeatTestApp::registerApps();
}
