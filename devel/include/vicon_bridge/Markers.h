// Generated by gencpp from file vicon_bridge/Markers.msg
// DO NOT EDIT!


#ifndef VICON_BRIDGE_MESSAGE_MARKERS_H
#define VICON_BRIDGE_MESSAGE_MARKERS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <vicon_bridge/Marker.h>

namespace vicon_bridge
{
template <class ContainerAllocator>
struct Markers_
{
  typedef Markers_<ContainerAllocator> Type;

  Markers_()
    : header()
    , frame_number(0)
    , markers()  {
    }
  Markers_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , frame_number(0)
    , markers(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _frame_number_type;
  _frame_number_type frame_number;

   typedef std::vector< ::vicon_bridge::Marker_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::vicon_bridge::Marker_<ContainerAllocator> >::other >  _markers_type;
  _markers_type markers;




  typedef boost::shared_ptr< ::vicon_bridge::Markers_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vicon_bridge::Markers_<ContainerAllocator> const> ConstPtr;

}; // struct Markers_

typedef ::vicon_bridge::Markers_<std::allocator<void> > Markers;

typedef boost::shared_ptr< ::vicon_bridge::Markers > MarkersPtr;
typedef boost::shared_ptr< ::vicon_bridge::Markers const> MarkersConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vicon_bridge::Markers_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vicon_bridge::Markers_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace vicon_bridge

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'vicon_bridge': ['/home/cflie/crazyflie_ws/src/vicon_bridge/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::vicon_bridge::Markers_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vicon_bridge::Markers_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vicon_bridge::Markers_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vicon_bridge::Markers_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vicon_bridge::Markers_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vicon_bridge::Markers_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vicon_bridge::Markers_<ContainerAllocator> >
{
  static const char* value()
  {
    return "579f0637989aa8139ce6bf98cf7aabda";
  }

  static const char* value(const ::vicon_bridge::Markers_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x579f0637989aa813ULL;
  static const uint64_t static_value2 = 0x9ce6bf98cf7aabdaULL;
};

template<class ContainerAllocator>
struct DataType< ::vicon_bridge::Markers_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vicon_bridge/Markers";
  }

  static const char* value(const ::vicon_bridge::Markers_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vicon_bridge::Markers_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
uint32 frame_number # Vicon Frame Number\n\
vicon_bridge/Marker[] markers # Array of Markers\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: vicon_bridge/Marker\n\
string marker_name\n\
string subject_name\n\
string segment_name\n\
geometry_msgs/Point translation\n\
bool occluded\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::vicon_bridge::Markers_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vicon_bridge::Markers_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.frame_number);
      stream.next(m.markers);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Markers_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vicon_bridge::Markers_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vicon_bridge::Markers_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "frame_number: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.frame_number);
    s << indent << "markers[]" << std::endl;
    for (size_t i = 0; i < v.markers.size(); ++i)
    {
      s << indent << "  markers[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::vicon_bridge::Marker_<ContainerAllocator> >::stream(s, indent + "    ", v.markers[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // VICON_BRIDGE_MESSAGE_MARKERS_H
