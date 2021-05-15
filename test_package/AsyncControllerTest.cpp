//
// Created by Leonid on 2019-03-09.
//

#include "AsyncControllerTest.hpp"

#include "test-controllers/TestAsyncController.hpp"

#include "oatpp-swagger/AsyncController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include <iostream>

namespace oatpp { namespace test { namespace swagger {

namespace {

  class SwaggerComponent {
  public:

    /**
     *  General API docs info
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)([] {

      oatpp::swagger::DocumentInfo::Builder builder;

      builder
        .setTitle("User entity service")
        .setDescription("CRUD API Example project with swagger docs")
        .setVersion("1.0")
        .setContactName("Ivan Ovsyanochka")
        .setContactUrl("https://oatpp.io/")

        .setLicenseName("Apache License, Version 2.0")
        .setLicenseUrl("http://www.apache.org/licenses/LICENSE-2.0")

        .addServer("http://localhost:8000", "server on localhost");

      return builder.build();

    }());


    /**
     *  Swagger-Ui Resources (<oatpp-examples>/lib/oatpp-swagger/res)
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)([] {
      // Make sure to specify correct full path to oatpp-swagger/res folder !!!
      return oatpp::swagger::Resources::loadResources(std::getenv("OATPP_SWAGGER_RES_PATH"));
    }());

  };

}

void AsyncControllerTest::onRun() {

  // Create ObjectMapper
  auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

  // Register swagger components
  SwaggerComponent swaggerComponent;

  // Create controllers and generate api docs
  auto docEndpoints = oatpp::swagger::AsyncController::Endpoints::createShared();

  auto controller = TestAsyncController::createShared(objectMapper);
  docEndpoints->pushBackAll(controller->getEndpoints());

  auto swaggerController = oatpp::swagger::AsyncController::createShared(docEndpoints);

  // TODO test generated document here
  OATPP_LOGV(TAG, "TODO implement test");

}

}}}