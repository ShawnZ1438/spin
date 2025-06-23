//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "SPINTestApp.h"
#include "SPINApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
SPINTestApp::validParams()
{
  InputParameters params = SPINApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

SPINTestApp::SPINTestApp(InputParameters parameters) : MooseApp(parameters)
{
  SPINTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

SPINTestApp::~SPINTestApp() {}

void
SPINTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  SPINApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"SPINTestApp"});
    Registry::registerActionsTo(af, {"SPINTestApp"});
  }
}

void
SPINTestApp::registerApps()
{
  registerApp(SPINApp);
  registerApp(SPINTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
SPINTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  SPINTestApp::registerAll(f, af, s);
}
extern "C" void
SPINTestApp__registerApps()
{
  SPINTestApp::registerApps();
}
