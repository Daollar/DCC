/**
 *  @file
 *  @copyright defined in actc/LICENSE
 */
#pragma once
#include <actc/test_control_plugin/test_control_plugin.hpp>
#include <actc/http_plugin/http_plugin.hpp>

#include <appbase/application.hpp>
#include <actc/chain/controller.hpp>

namespace actc {
   using actc::chain::controller;
   using std::unique_ptr;
   using namespace appbase;

   class test_control_api_plugin : public plugin<test_control_api_plugin> {
      public:
        APPBASE_PLUGIN_REQUIRES((test_control_plugin)(chain_plugin)(http_plugin))

        test_control_api_plugin();
        virtual ~test_control_api_plugin();

        virtual void set_program_options(options_description&, options_description&) override;

        void plugin_initialize(const variables_map&);
        void plugin_startup();
        void plugin_shutdown();

      private:
        unique_ptr<class test_control_api_plugin_impl> my;
   };

}
