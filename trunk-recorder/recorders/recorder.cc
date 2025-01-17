#include "recorder.h"
#include "../source.h"
#include <boost/algorithm/string.hpp>

Recorder::Recorder(std::string type) {
  this->type = type;
}

boost::property_tree::ptree Recorder::get_stats() {
  boost::property_tree::ptree node;
  node.put("id", boost::lexical_cast<std::string>(get_source()->get_num()) + "_" + boost::lexical_cast<std::string>(get_num()));
  node.put("type", type);
  node.put("srcNum", get_source()->get_num());
  node.put("recNum", get_num());
  node.put("count", recording_count);
  node.put("duration", recording_duration);
  node.put("state", get_state());
  return node;
}