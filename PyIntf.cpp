#include <boost/python.hpp>
#include "DlepInit.h"
#include "PeerDiscovery.h"
#include "ExampleDlepClientImpl.h"
#include "DlepClient.h" // base class
#include "DlepServiceImpl.h"
#include "DlepService.h"
#include "Dlep.h"
#include "ProtocolConfigImpl.h"
// An established convention for using boost.python.

using namespace LLDLEP;
using namespace internal;
//using namespace boost::python;


// Assist in transorming namespace LLDLEP into Python scope 
class DummyLLDLEP{}; 

// Function to return the pointer to DlepClientImpl object
DlepClient* get_base()
{
  return new DlepClientImpl;
}

LLDLEP::ProtocolConfig* get_Ptr_ProtocolConfig()
{
	return new ProtocolConfigImpl;
}

class ProtocolConfigWrap: public  LLDLEP::ProtocolConfig, public boost::python::wrapper<LLDLEP::ProtocolConfig> {
	
	public:
	
	ProtocolConfigWrap(){}
	std::array<std::uint16_t, 2> get_version()
	{
		return this->get_override("get_version")();
	}
    	std::size_t get_data_item_id_size()
	{
		return this->get_override("get_data_item_id_size")();
	}
    	std::size_t get_data_item_length_size()
	{
		return this->get_override("get_data_item_length_size")();
	}
    	DataItemIdType get_data_item_id(const std::string & name, const LLDLEP::DataItemInfo * parent_di_info = nullptr)
	{
		return this->get_override("get_data_item_id")(&name, parent_di_info ); // Check it
	}
    	std::string get_data_item_name(DataItemIdType id, const LLDLEP::DataItemInfo * parent_di_info = nullptr)
	{
		return this->get_override("get_data_item_name")(id, parent_di_info);
	}
    	DataItemValueType get_data_item_value_type(const std::string & name)
	{
		return this->get_override("get_data_item_value_type")(&name); //check it
	}
    	bool is_metric(DataItemIdType id, const LLDLEP::DataItemInfo * parent_di_info = nullptr)
	{
		return this->get_override("is_metric")(id, parent_di_info);
	}
        bool is_ipaddr(DataItemIdType id, const LLDLEP::DataItemInfo * parent_di_info = nullptr)
	{
		return this->get_override("is_ipaddr")(id, parent_di_info);
	}
	std::vector<LLDLEP::DataItemInfo> get_data_item_info()
	{
		return this->get_override("get_data_item_info")();
	}
    	LLDLEP::DataItemInfo get_data_item_info(const std::string & di_name)
	{
		return this->get_override("get_data_item_info")(& di_name);
	}

    	LLDLEP::DataItemInfo get_data_item_info(DataItemIdType id, const LLDLEP::DataItemInfo * parent_di_info = nullptr)
	{
		return this->get_override("get_data_item_info")(id, parent_di_info);
	}	
	std::vector<LLDLEP::DataItemInfo> get_data_item_info(const std::vector<std::string> & di_names)
	{
		return this->get_override("get_data_item_info")(&di_names);
	}

    	std::size_t get_signal_id_size()
	{
		return this->get_override("get_signal_id_size")();
	}
    	std::size_t get_signal_length_size()
	{
		return this->get_override("get_signal_length_size")();
	}
    	SignalIdType get_signal_id(const std::string & name, bool * is_signal_return = nullptr)
	{
		return this->get_override("get_signal_id")(& name,is_signal_return);
	}
    	std::string get_signal_name(SignalIdType id)
	{
		return this->get_override("get_signal_name")(id);
	}
    	std::string get_message_name(SignalIdType id)
	{
		return this->get_override("get_message_name")(id);
	}

	std::string get_message_response_name(const std::string & name)
	{
		return this->get_override("get_message_response_name")(& name);
	}
	std::string get_signal_prefix()
	{
		return this->get_override("get_signal_prefix")();
	}
    	std::vector<SignalInfo> get_signal_info()
	{
		return this->get_override("get_signal_info")();
	}
    	SignalInfo get_signal_info(const std::string & sig_name)
	{
		return this->get_override("get_signal_info")(& sig_name);
	}
    	std::vector<SignalInfo> get_signal_info(const std::vector<std::string> & sig_names)
	{
		return this->get_override("get_signal_info")(& sig_names);
	}
    	std::size_t get_status_code_size()
	{
		return this->get_override("get_status_code_size")();
	}
	StatusCodeIdType get_status_code_id(const std::string & name)
	{
		return this->get_override("get_status_code_id")(& name);
	}
	std::string get_status_code_name(StatusCodeIdType id)
	{
		return this->get_override("get_status_code_name")(id);
	}
    	std::vector<StatusCodeInfo> get_status_code_info()
	{	
		return this->get_override("get_status_code_info")();
	}
    	StatusCodeInfo get_status_code_info(const std::string & sc_name)
	{
		return this->get_override("get_status_code_info")( & sc_name);
	}
	std::vector<StatusCodeInfo> get_status_code_info(const std::vector<std::string> & sc_names)
	{
		return this->get_override("get_status_code_info")( & sc_names);
	}
	std::vector<ModuleInfo> get_module_info()
	{
		return this->get_override("get_module_info")();
	}
	ModuleInfo get_module_info(const std::string & module_name)
	{
		return this->get_override("get_module_info")(& module_name);
	}
    	std::vector<ModuleInfo> get_module_info(const std::vector<std::string> & module_names)
	{
		return this->get_override("get_module_info")(& module_names);
	}
    	std::size_t get_extension_id_size()
	{
		return this->get_override("get_extension_id_size")();
	}
	std::vector<ExtensionIdType> get_extension_ids()
	{
		return this->get_override("get_extension_ids")();
	}
 	std::vector<std::string> get_experiment_names()
	{
		return this->get_override("get_experiment_names")();
	}
	~ProtocolConfigWrap() {
		this->get_override("~ProtocolConfig");
	};	


};





class DlepClientWrap : public LLDLEP::DlepClient, public boost::python::wrapper<LLDLEP::DlepClient> {

	public: 

	DlepClientWrap(){}

    	void get_config_parameter(const std::string & parameter_name, ConfigValue * value)
	{
		this->get_override("get_config_parameter")(parameter_name, value);
	}

	void  get_config_parameter(const std::string & parameter_name,  bool * value)
	{
		this->get_override("get_config_parameter")(parameter_name,value);
	}

	void  get_config_parameter(const std::string & parameter_name,  unsigned int * value)
	{ 
		this->get_override("get_config_parameter")(parameter_name,value);
	}
	void  get_config_parameter(const std::string & parameter_name,  std::string * value)
	{ 
		this->get_override("get_config_parameter")(parameter_name,value);
	}
	void  get_config_parameter(const std::string & parameter_name,  boost::asio::ip::address * value)
	{ 
		this->get_override("get_config_parameter")(parameter_name,value);
	}	
	void  get_config_parameter(const std::string & parameter_name,  std::vector<unsigned int> * value)
	{
		this->get_override("get_config_parameter")(parameter_name,value);
	}

        void peer_up(const LLDLEP::PeerInfo & peer_info)
	{
		this->get_override("peer_up")(peer_info);
	}

	void peer_update(const std::string & peer_id, const DataItems & data_items)
	{
		this->get_override("peer_update")(peer_id, data_items);
	}

	void peer_down(const std::string & peer_id)
	{
		this->get_override("peer_down")(peer_id);
	}

    	std::string destination_up(const std::string & peer_id, const DlepMac & mac_address, const DataItems & data_items)
	{
		return this->get_override("destination_up")(peer_id, mac_address, data_items);
	}

   	void destination_update(const std::string & peer_id,
                                    const DlepMac & mac_address,
                                    const DataItems & data_items)
	{
		this->get_override("destination_update")(peer_id, mac_address, data_items);

	}

    	void destination_down(const std::string & peer_id,
                                  const DlepMac & mac_address)
	{
		this->get_override("destination_down")(peer_id, mac_address);
	}

   	void linkchar_request(const std::string & peer_id,
                                  const DlepMac & mac_address,
                                  const DataItems & data_items) 
	{
		this->get_override("linkchar_request")(peer_id, mac_address, data_items);

	}

      	void linkchar_reply(const std::string & peer_id,
                                const DlepMac & mac_address,
                                const DataItems & data_items)

	{
		this->get_override("linkchar_reply")(peer_id, mac_address, data_items);
	}


};


class DlepClientImplWrap : public DlepClientImpl,  public boost::python::wrapper<DlepClientImpl> { 

	public:

	DlepClientImplWrap() : DlepClientImpl(){}

	void  get_config_parameter( const std::string & parameter_name,  DlepClientImplWrap::ConfigValue * value) 
	{
		this->get_override("get_config_parameter")(parameter_name,value);
	}
	void  get_config_parameter(const std::string & parameter_name,  bool * value)
	{
		this->get_override("get_config_parameter")(parameter_name,value);
	}

	void  get_config_parameter(const std::string & parameter_name,  unsigned int * value)
	{ 
		this->get_override("get_config_parameter")(parameter_name,value);
	}
	void  get_config_parameter(const std::string & parameter_name,  std::string * value)
	{ 
		this->get_override("get_config_parameter")(parameter_name,value);
	}
	void  get_config_parameter(const std::string & parameter_name,  boost::asio::ip::address * value)
	{ 
		this->get_override("get_config_parameter")(parameter_name,value);
	}	
	void  get_config_parameter(const std::string & parameter_name,  std::vector<unsigned int> * value)
	{
		this->get_override("get_config_parameter")(parameter_name,value);
	}

    	void print_data_items(const std::string & msg, const LLDLEP::DataItems & data_items)
	{
		this->get_override("print_data_items")(msg, data_items);
	}

    	void print_peer_info(const LLDLEP::PeerInfo & peer_info)
	{
		this->get_override("print_peer_info")(peer_info);
	}
    	void peer_up(const LLDLEP::PeerInfo & peer_info)
	{
		this->get_override("peer_up")(peer_info);
	}

    	void peer_update(const std::string & peer_id, const LLDLEP::DataItems & data_items)
	{
		this->get_override("peer_update")(peer_id, data_items);
	}

    	void peer_down(const std::string & peer_id)
	{
		this->get_override("peer_down")(peer_id);
	}

    	std::string destination_up(const std::string & peer_id,
                               const LLDLEP::DlepMac & mac_address,
                               const LLDLEP::DataItems & data_items)
	{
		return this->get_override("destination_up")(peer_id, mac_address, data_items);
	}

    	void destination_update(const std::string & peer_id,
                            const LLDLEP::DlepMac & mac_address,
                            const LLDLEP::DataItems & data_items)
	{
		this->get_override("destination_update")(peer_id, mac_address, data_items);
	}
    	void destination_down(const std::string & peer_id,
                          const LLDLEP::DlepMac & mac_address)
	{
		this->get_override("destination_down")(peer_id, mac_address);
	}

    	void linkchar_request(const std::string & peer_id,
                          const LLDLEP::DlepMac & mac_address,
                          const LLDLEP::DataItems & data_items)
	{
		this->get_override("linkchar_request")(peer_id, mac_address, data_items);
	}

    	void linkchar_reply(const std::string & peer_id,
                        const LLDLEP::DlepMac & mac_address,
                        const LLDLEP::DataItems & data_items)
	{
		this->get_override("linkchar_reply")(peer_id, mac_address, data_items);
	}

    	//bool parse_args(int argc, char ** argv); No need to expose

    	/// Fill in default configuration parameter values.
    	bool load_defaults()
	{
		return this->get_override("load_defaults");
	}

    	/// Parse one configuration parameter and put it into the configuration
    	//bool parse_parameter(const char * param_name, const char * param_value);

    	/// Print the contents of the configuration database.
    	void print_config() const
	{
		this->get_override("print_config");	
	}

    	/// Print a usage message.
    	//void usage(const char * progname) const;

    	void set_dlep_service(LLDLEP::DlepService * ds)
	{
	 	this->get_override("set_dlep_service")(ds);
	}

    	/// Define the status code to use in response to a future destination up.
    	void set_destination_response(const LLDLEP::DlepMac & mac_address,
                                  const std::string & status_code)
	{
		this->get_override("set_destination_response")(mac_address, status_code);
	}

};


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class DlepServiceWrap : public LLDLEP::DlepService, public boost::python::wrapper<LLDLEP::DlepService> {

	public: 	

	ReturnStatus destination_up(const DlepMac & mac_address, const DataItems & data_items)
	{
		return this->get_override("destination_up")(mac_address, data_items);	
	}

	ReturnStatus destination_update(const DlepMac & mac_address, const DataItems & data_items)
	{
		return this->get_override("destination_update")(mac_address, data_items);
	}

	ReturnStatus destination_down(const DlepMac & mac_address)
	{
		return this->get_override("destination_down")(mac_address);
	}
	ReturnStatus peer_update(const DataItems & data_items)
	{
		return this->get_override("peer_update")(data_items);
	}
	ReturnStatus get_peers(std::vector<std::string> & peers)
	{
		return this->get_override("get_peers")(peers);
	}
	ReturnStatus get_peer_info(const std::string & peer_id,
                                       LLDLEP::PeerInfo & peer_info)
	{
		return this->get_override("get_peer_info")(peer_id, peer_info);
	}
	ReturnStatus get_destination_info(const std::string & peer_id,
                                              const DlepMac & mac_address,
                                              LLDLEP::DestinationInfo & dest_info)
	{
		return this->get_override("get_destination_info")(peer_id, mac_address, dest_info);	
	}
	

	LLDLEP::ProtocolConfig * get_protocol_config()
	{
		return this->get_override("get_protocol_config")();
	}

	ReturnStatus linkchar_request(const DlepMac & mac_address,
                                          const DataItems & data_items)
	{
		return this->get_override("linkchar_request")(mac_address, data_items);
	}
	ReturnStatus linkchar_reply(const std::string & peer_id,
                                        const DlepMac & mac_address,
                                        const DataItems & data_items)
	{
		return this->get_override("linkchar_reply")(peer_id, mac_address, data_items);
	}	

	void terminate()
	{
		this->get_override("terminate")();
	} 

   	~DlepServiceWrap() 
	{
		this->get_override("~DlepService");
	};


 	DlepServiceWrap() 
	{
 		this->get_override("DlepService");
	}; 

};




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Create Wrapper for Class DlepServiceImpl

class DlepServiceImplWrap : public LLDLEP::internal::DlepServiceImpl, public boost::python::wrapper<LLDLEP::internal::DlepServiceImpl> {

	public:
 	
	DlepServiceImplWrap(DlepPtr dlep, DlepLoggerPtr logger){
		this->get_override("DlepServiceImpl")(dlep, logger);

	};
	
	ReturnStatus destination_up(const LLDLEP::DlepMac & mac_address,
                                const LLDLEP::DataItems & data_items)
	{
		return this->get_override("destination_up")(mac_address, data_items);
	}

    	ReturnStatus destination_update(const LLDLEP::DlepMac & mac_address,
                                    const LLDLEP::DataItems & data_items)

	{
		return this->get_override("destination_update")(mac_address, data_items);
	}

    	ReturnStatus destination_down(const LLDLEP::DlepMac & mac_address) 

	{
		return this->get_override("destination_down")(mac_address);
	}

    	ReturnStatus peer_update(const LLDLEP::DataItems & data_items)
	{
		return this->get_override("peer_update")(data_items);
	}


    	ReturnStatus get_peers(std::vector<std::string> & peers)
	{
		return this->get_override("get_peers")(peers);
	}


    	ReturnStatus get_peer_info(const std::string & peer_id,
                               LLDLEP::PeerInfo & peer_info)
	{
		return this->get_override("get_peer_info")(peer_id, peer_info);
	}


    	ReturnStatus get_destination_info(const std::string & peer_id,
                                      const LLDLEP::DlepMac & mac_address,
                                      LLDLEP::DestinationInfo & dest_info)
	{
		return this->get_override("get_destination_info")(peer_id, mac_address, dest_info);
	}

    	LLDLEP::ProtocolConfig * get_protocol_config()
	{
		return	this->get_override("get_protocol_config")();
	}


   	ReturnStatus linkchar_request(const DlepMac & mac_address,
                                  const DataItems & data_items)
	{
		return this->get_override("linkchar_request")(mac_address, data_items);
	}
    	
	ReturnStatus linkchar_reply(const std::string & peer_id,
                                const DlepMac & mac_address,
                                const DataItems & data_items)
	{
		return this->get_override("linkchar_reply")(peer_id, mac_address, data_items);
	}

	void terminate()
	{
		this->get_override("terminate")();
	}

};


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
BOOST_PYTHON_MODULE(libdlep) {
     
    // List of functions from DlepInit.h need to be exposed                
 
    using namespace boost::python;

  

    // List of functions from DlepService.h need to be exposed 
     

	scope LLDLEP	=  class_<DummyLLDLEP>("LLDLEP");
/*	boost::python::class_<DlepClientWrap, boost::noncopyable>("DlepClient", boost::python::init<>())
	;
	
*/
        def("DlepInit", &DlepInit, return_value_policy<manage_new_object>()); 

	// Exposing overloaded methods 	
     	// List of functions from DlepClient.h need to be exposed
	void	(DlepClientWrap::*d1)( const std::string & parameter_name,  LLDLEP::DlepClient::ConfigValue * value)   = & LLDLEP::DlepClient::get_config_parameter;
    	void	(DlepClientWrap::*d2)( const std::string & parameter_name,  bool * value) = & DlepClientWrap:: get_config_parameter;
    	void	(DlepClientWrap::*d3)( const std::string & parameter_name,  unsigned int * value)  = & DlepClientWrap::get_config_parameter;
  	void	(DlepClientWrap::*d4)( const std::string & parameter_name,  std::string * value)   = & DlepClientWrap::get_config_parameter;
    	void	(DlepClientWrap::*d5)( const std::string & parameter_name,  boost::asio::ip::address * value) = & DlepClientWrap::get_config_parameter;
    	void	(DlepClientWrap::*d6)( const std::string & parameter_name,  std::vector<unsigned int> * value)  = & DlepClientWrap::get_config_parameter;
	//boost::python::class_<DlepClientWrap>("DlepClient", no_init) 
	boost::python::class_<DlepClientWrap, boost::noncopyable>("DlepClientWrap", boost::python::init<>())
    		.def("get_config_parameter", pure_virtual(d1))
		.def("get_config_parameter", pure_virtual(d2))
                .def("get_config_parameter", pure_virtual(d3))
		.def("get_config_parameter", pure_virtual(d4))
		.def("get_config_parameter", pure_virtual(d5))
		.def("get_config_parameter", pure_virtual(d6))
		// Exposing non-overloaded methods
		.def("peer_up", pure_virtual(&DlepClientWrap::peer_up))
		.def("peer_update", pure_virtual(&DlepClientWrap::peer_update))
		.def("peer_down", pure_virtual(&DlepClientWrap::peer_down))
		.def("destination_up",pure_virtual(&DlepClientWrap::destination_up))
		.def("destination_update", pure_virtual(&DlepClientWrap::destination_update))
		.def("destination_down", pure_virtual(&DlepClientWrap::destination_down))
		.def("linkchar_request", pure_virtual(&DlepClientWrap::linkchar_request))
		.def("linkchar_reply", pure_virtual(&DlepClientWrap::linkchar_reply))
	
	;


     // Function overloading
  	void	(DlepClientImplWrap::*d7)( const std::string & parameter_name,  DlepClientImplWrap::ConfigValue * value)   = & DlepClientImplWrap::get_config_parameter;
	void	(DlepClientImplWrap::*d8)( const std::string & parameter_name,  bool * value) = & DlepClientImplWrap:: get_config_parameter;
    	void	(DlepClientImplWrap::*d9)( const std::string & parameter_name,  unsigned int * value)  = & DlepClientImplWrap:: get_config_parameter;
	void	(DlepClientImplWrap::*d10)( const std::string & parameter_name,  std::string * value)   = & DlepClientImplWrap::get_config_parameter;
    	void	(DlepClientImplWrap::*d11)( const std::string & parameter_name,  boost::asio::ip::address * value) = & DlepClientImplWrap:: get_config_parameter;
    	void	(DlepClientImplWrap::*d12)( const std::string & parameter_name,  std::vector<unsigned int> * value)  = & DlepClientImplWrap:: get_config_parameter;

	
       //class_<DlepClientImpl, bases<DlepClient>>("DlepClientImpl", init<std::string,std::string,std::string,std::string, DlepService *>())

        boost::python::class_<DlepClientImplWrap, boost::noncopyable>("DlepClientImplWrap", boost::python::init<>())
		.def("peer_update", &DlepClientImplWrap::peer_update)
		.def("peer_down", &DlepClientImplWrap::peer_down)
	  	.def("peer_up", &DlepClientImplWrap::peer_up)
	        .def("destination_up", &DlepClientImplWrap::destination_up)
		.def("destination_update", &DlepClientImplWrap::destination_update)
		.def("destination_down", &DlepClientImplWrap::destination_down)
	        .def("linkchar_request", &DlepClientImplWrap::linkchar_request)
	        .def("linkchar_reply", &DlepClientImplWrap::linkchar_reply)	
		.def("load_defaults", &DlepClientImplWrap::load_defaults)
	    	.def("print_config",&DlepClientImplWrap::print_config)
        // Function overloading
		.def("get_config_parameter", d7)
	        .def("get_config_parameter", d8)
	        .def("get_config_parameter", d9)
	        .def("get_config_parameter", d10)
	        .def("get_config_parameter", d11)
		.def("get_config_parameter", d12)
	        ;


	boost::python::class_<DlepServiceWrap, boost::noncopyable>("DlepServiceWrap", boost::python::init<>())
		.def("destination_up", &DlepServiceWrap::destination_up)
		.def("destination_update", & DlepServiceWrap::destination_update)
		.def("destination_down",& DlepServiceWrap::destination_down)
		.def("peer_update", & DlepServiceWrap::peer_update)
		.def("get_peers", & DlepServiceWrap::get_peers)
		.def("get_peer_info", & DlepServiceWrap::get_peer_info)
		.def("get_destination_info",& DlepServiceWrap::get_destination_info)
		.def("get_protocol_config",& DlepServiceWrap::get_protocol_config)
		.def("linkchar_request", & DlepServiceWrap::linkchar_request)
		.def("linkchar_reply", & DlepServiceWrap::linkchar_reply)
		.def("terminate", & DlepServiceWrap::terminate)
		;
	
	boost::python::class_<DlepServiceImplWrap, boost::noncopyable>("DlepServiceWrap", boost::python::init<>())
		
		.def("destination_up", &DlepServiceImplWrap::destination_up)
		.def("destination_update", & DlepServiceImplWrap::destination_update)
		.def("destination_down",& DlepServiceImplWrap::destination_down)
		.def("peer_update", & DlepServiceImplWrap::peer_update)
		.def("get_peers", & DlepServiceImplWrap::get_peers)
		.def("get_peer_info", & DlepServiceImplWrap::get_peer_info)
		.def("get_destination_info",& DlepServiceImplWrap::get_destination_info)
		.def("get_protocol_config",& DlepServiceImplWrap::get_protocol_config)
		.def("linkchar_request", & DlepServiceImplWrap::linkchar_request)
		.def("linkchar_reply", & DlepServiceImplWrap::linkchar_reply)
		.def("terminate", & DlepServiceImplWrap::terminate)
		;






        //Registering Converter for Variant of Type Int
        //   LLDLEP::iterable_converter().from_python<std::vector<int> >();


		

	
//	.def("set_String_Container", &DlepClientImpl::set_String_Container)
//	.def("set_Int_Container", &DlepClientImpl::set_Int_Container)
//	.def("set_Bool_Container", &DlepClientImpl::set_Bool_Container)
//	.def("set_IpAddress_Container", &DlepClientImpl::set_IpAddress_Container)
//	.def("set_Vector_Container", &DlepClientImpl::set_Vector_Container)
//	.def("get_String_Container", &DlepClientImpl::get_String_Container)
//	.def("get_Int_Container", &DlepClientImpl::get_Int_Container)
//	.def("get_Bool_Container", &DlepClientImpl::get_Bool_Container)
//	.def("get_IpAddress_Container", &DlepClientImpl::get_IpAddress_Container)
//	.def("getVectorValueByIndex", &DlepClientImpl::getVectorValueByIndex)
//	.def("getVectorSize", &DlepClientImpl::getVectorSize)
//	.def("get_Vector_Container", &DlepClientImpl::get_Vector_Container)
         

 //  .def("get_config_parameter", &DlepClient::get_config_parameter)
       //  .def("__exit__", &DlepClient::exit)     
	//.def("peer_up",&&LLDLEP::DlepClient::peer_up)    
       ;


       

	//Expose the method to create Base class pointer
 	def("get_base", &get_base, return_value_policy<reference_existing_object>()); //ignore mem leak
	def("get_Ptr_ProtocolConfig", &get_Ptr_ProtocolConfig, return_value_policy<reference_existing_object>()); 

}

