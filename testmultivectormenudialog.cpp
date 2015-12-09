//---------------------------------------------------------------------------
/*
TestMultiVector, tests the MultiVector class
Copyright (C) 2011-2015  Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/ToolTestMultiVector.htm
//---------------------------------------------------------------------------
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "testmultivectormenudialog.h"

#include <cassert>
#include <iostream>

#include <boost/units/unit.hpp>
#include <boost/units/systems/si.hpp>

#include "multivector.h"
#include "trace.h"
#include "testtimer.h"

#pragma GCC diagnostic pop

ribi::TestMultiVectorMenuDialog::TestMultiVectorMenuDialog()
{
  #ifndef NDEBUG
  Test();
  #endif
}

int ribi::TestMultiVectorMenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc == 1)
  {
    std::cout << GetHelp() << '\n';
    return 1;
  }
  assert(!"TODO");
  return 1;
}

ribi::About ribi::TestMultiVectorMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "ToolTestMultiVector",
    "tests the MultiVector class",
    "the 14th of June 2015",
    "2015-2015",
    "http://www.richelbilderbeek.nl/ToolTestMultiVector.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("MultiVector version: " + MultiVector<int>::GetVersion());
  a.AddLibrary("Trace version: " + Trace::GetVersion());
  return a;
}

ribi::Help ribi::TestMultiVectorMenuDialog::GetHelp() const noexcept
{
  return Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {

    },
    {

    }
  );
}

std::string ribi::TestMultiVectorMenuDialog::GetVersion() const noexcept
{
  return "2.0";
}

std::vector<std::string> ribi::TestMultiVectorMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2015-06-14: version 1.0: initial versioning",
    "2015-12-09: version 2.0: moved to own GitHub",
  };
}

#ifndef NDEBUG
void ribi::TestMultiVectorMenuDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  {
    TestMultiVector();
  }
  const TestTimer test_timer(__func__,__FILE__,1.0);
}
#endif
