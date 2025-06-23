#include "SPINApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
SPINApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

SPINApp::SPINApp(InputParameters parameters) : MooseApp(parameters)
{
  SPINApp::registerAll(_factory, _action_factory, _syntax);
}

SPINApp::~SPINApp() {}

void
SPINApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<SPINApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"SPINApp"});
  Registry::registerActionsTo(af, {"SPINApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
SPINApp::registerApps()
{
  registerApp(SPINApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
SPINApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  SPINApp::registerAll(f, af, s);
}
extern "C" void
SPINApp__registerApps()
{
  SPINApp::registerApps();
}
