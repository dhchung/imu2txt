#include "parameters_json.h"

Params::Params(){

}

Params::~Params(){

}

bool Params::read_data(std::string json_dir) {

    bool param_open = false;
    std::ifstream stream;
    stream.open(json_dir);

    if(stream.is_open()) {
        Json::Value root;
        stream >> root;

        Json::Value io_params = root["io_params"];
        Json::ValueIterator it = io_params.begin();
        it = io_params.begin();

        while(it != io_params.end()) {
            if(it->isObject()) {
                std::string name = (*it)["name"].asString();
                if(name == "input_bag") {
                    IOParam.input_bag = (*it)["value"].asString();
                }else if(name=="output_dir") {
                    IOParam.output_dir = (*it)["value"].asString();
                }
            }
            ++it;
        }
        IOParam.PrintStuff();
        param_open = true;
    } else {
        param_open = false;
    }
    return param_open;
}
