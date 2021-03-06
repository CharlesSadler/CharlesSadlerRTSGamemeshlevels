// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "MCLGridRef.pypp.hpp"

namespace bp = boost::python;

void register_MCLGridRef_class(){

    { //::CEGUI::MCLGridRef
        typedef bp::class_< CEGUI::MCLGridRef > MCLGridRef_exposer_t;
        MCLGridRef_exposer_t MCLGridRef_exposer = MCLGridRef_exposer_t( "MCLGridRef", "*!\n\
        \n\
           Simple grid index structure.\n\
        *\n", bp::init< CEGUI::uint, CEGUI::uint >(( bp::arg("r"), bp::arg("c") )) );
        bp::scope MCLGridRef_scope( MCLGridRef_exposer );
        MCLGridRef_exposer.def( bp::self != bp::self );
        MCLGridRef_exposer.def( bp::self < bp::self );
        MCLGridRef_exposer.def( bp::self <= bp::self );
        { //::CEGUI::MCLGridRef::operator=
        
            typedef ::CEGUI::MCLGridRef & ( ::CEGUI::MCLGridRef::*assign_function_type )( ::CEGUI::MCLGridRef const & ) ;
            
            MCLGridRef_exposer.def( 
                "assign"
                , assign_function_type( &::CEGUI::MCLGridRef::operator= )
                , ( bp::arg("rhs") )
                , bp::return_self< >()
                , "operators\n" );
        
        }
        MCLGridRef_exposer.def( bp::self == bp::self );
        MCLGridRef_exposer.def( bp::self > bp::self );
        MCLGridRef_exposer.def( bp::self >= bp::self );
        MCLGridRef_exposer.def_readwrite( "column", &CEGUI::MCLGridRef::column );
        MCLGridRef_exposer.def_readwrite( "row", &CEGUI::MCLGridRef::row );
    }

}
