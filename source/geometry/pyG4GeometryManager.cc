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
// $Id: pyG4GeometryManager.cc,v 1.1 2008-12-03 07:21:56 kmura Exp $
// $Name: geant4-09-04-patch-02 $
// ====================================================================
//   pyG4GeometryManager.cc
//
//                                         2008 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4GeometryManager.hh"
#include "G4VPhysicalVolume.hh"

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4GeometryManager {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(f_CloseGeometry, CloseGeometry, 0, 3);
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(f_OpenGeometry, OpenGeometry, 0, 1);

};

using namespace pyG4GeometryManager;

// ====================================================================
// module definition
// ====================================================================
void export_G4GeometryManager()
{
  class_<G4GeometryManager, boost::noncopyable>
    ("G4GeometryManager", "geometry manager", no_init)
    .def("GetInstance",           &G4GeometryManager::GetInstance,
         return_value_policy<reference_existing_object>())
    .staticmethod("GetInstance")
    // ---
    .def("CloseGeometry",         &G4GeometryManager::CloseGeometry, 
         f_CloseGeometry())
    .def("OpenGeometry",          &G4GeometryManager::OpenGeometry,
         f_OpenGeometry())
    .def("IsGeometryClosed",      &G4GeometryManager::IsGeometryClosed)
    .def("SetWorldMaximumExtent", &G4GeometryManager::SetWorldMaximumExtent)
    ;
}
