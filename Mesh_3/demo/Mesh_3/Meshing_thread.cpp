// Copyright (c) 2010 INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
//
// Author(s)     : Stephane Tayeb
//
//******************************************************************************
// File Description : 
//******************************************************************************


#include <QTime>
#include "Meshing_thread.h"
#include "Scene_c3t3_item.h"


Meshing_thread::
Meshing_thread(Mesh_function_interface* f, Scene_c3t3_item* item)
  : f_(f)
  , item_(item)
  , time_(0)
{
  
}


Meshing_thread::
~Meshing_thread()
{
  delete f_;
}


void
Meshing_thread::
run()
{
  QTime timer;
  timer.start();
  
  f_->launch();
  time_ = double(timer.elapsed()) / 1000;
  
  item_->c3t3_changed();
  
  emit done(this);
}


void
Meshing_thread::
stop()
{
  f_->stop();
}


#include "Meshing_thread.moc"