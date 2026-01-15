// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from center_msg_pkg:msg/Center.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "center_msg_pkg/msg/detail/center__struct.h"
#include "center_msg_pkg/msg/detail/center__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "center_msg_pkg/msg/detail/singlecenter__functions.h"
// end nested array functions include
bool center_msg_pkg__msg__singlecenter__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * center_msg_pkg__msg__singlecenter__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool center_msg_pkg__msg__center__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[34];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("center_msg_pkg.msg._center.Center", full_classname_dest, 33) == 0);
  }
  center_msg_pkg__msg__Center * ros_message = _ros_message;
  {  // boxes
    PyObject * field = PyObject_GetAttrString(_pymsg, "boxes");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'boxes'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!center_msg_pkg__msg__Singlecenter__Sequence__init(&(ros_message->boxes), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create center_msg_pkg__msg__Singlecenter__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    center_msg_pkg__msg__Singlecenter * dest = ros_message->boxes.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!center_msg_pkg__msg__singlecenter__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // box_num
    PyObject * field = PyObject_GetAttrString(_pymsg, "box_num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->box_num = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * center_msg_pkg__msg__center__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Center */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("center_msg_pkg.msg._center");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Center");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  center_msg_pkg__msg__Center * ros_message = (center_msg_pkg__msg__Center *)raw_ros_message;
  {  // boxes
    PyObject * field = NULL;
    size_t size = ros_message->boxes.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    center_msg_pkg__msg__Singlecenter * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->boxes.data[i]);
      PyObject * pyitem = center_msg_pkg__msg__singlecenter__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "boxes", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // box_num
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->box_num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "box_num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
