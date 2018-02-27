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
// $Id: pyG4MaterialPropertiesTable.cc,v 1.7 2008-12-04 08:55:25 kmura Exp $
// $Name: geant4-09-04-patch-02 $
// ====================================================================
//   pyG4Material.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4Version.hh"
#include "G4MaterialPropertiesTable.hh"
#include <vector>

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4MaterialPropertiesTable {

  // AddElement
  void f1_AddProperty(G4MaterialPropertiesTable *table, const char *key, list photon_energies, list property_values)
  {
    std::vector<double> v_energies(len(photon_energies));
    std::vector<double> v_values(len(property_values));
    
    for (unsigned int i=0; i < v_energies.size(); i++)
      v_energies[i] = extract<double>(photon_energies[i]);
    for (unsigned int i=0; i < v_values.size(); i++)
      v_values[i] = extract<double>(property_values[i]);
    
    table->AddProperty(key, &v_energies.front(), &v_values.front(), v_energies.size());
  }
}

using namespace pyG4MaterialPropertiesTable;

// ====================================================================
// module definition
// ====================================================================
void export_G4MaterialPropertiesTable()
{
  class_<G4MaterialPropertiesTable, G4MaterialPropertiesTable*, boost::noncopyable>
    ("G4MaterialPropertiesTable", "material properties table class")
    .def("AddConstProperty",    &G4MaterialPropertiesTable::AddConstProperty)
    .def("AddProperty",    f1_AddProperty)
    .def("RemoveConstProperty", &G4MaterialPropertiesTable::RemoveConstProperty)
    .def("RemoveProperty", &G4MaterialPropertiesTable::RemoveProperty)
    //.def("GetConstProperty", &G4MaterialPropertiesTable::GetConstProperty)
    .def("ConstPropertyExists", &G4MaterialPropertiesTable::ConstPropertyExists)
    //.def("GetProperty", &G4MaterialPropertiesTable::GetProperty,
	// return_value_policy<reference_existing_object>())
    .def("AddEntry", &G4MaterialPropertiesTable::AddEntry)
    // ?? .def("RemoveEntry", &G4MaterialPropertiesTable::RemoveEntry)
    .def("DumpTable", &G4MaterialPropertiesTable::DumpTable)
    ;
}

