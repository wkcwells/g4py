//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: pyG4StepStatus.cc,v 1.4 2006-06-29 15:35:42 gunter Exp $
// $Name: geant4-09-04-patch-02 $
// ====================================================================
//   pyG4StepStatus.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4StepStatus.hh"

using namespace boost::python;

// ====================================================================
// module definition
// ====================================================================
void export_G4StepStatus()
{
  enum_<G4StepStatus>("G4StepStatus")
    .value("fWorldBoundary",         fWorldBoundary)
    .value("fGeomBoundary",          fGeomBoundary)
    .value("fAtRestDoItProc",        fAtRestDoItProc)
    .value("fAlongStepDoItProc",     fAlongStepDoItProc)
    .value("fPostStepDoItProc",      fPostStepDoItProc)
    .value("fUserDefinedLimit",      fUserDefinedLimit)
    .value("fExclusivelyForcedProc", fExclusivelyForcedProc)
    .value("fUndefined",             fUndefined)
    ;
}
