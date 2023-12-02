#if defined(__clang__)

#include "babble"

#include <OpenColorIO/OpenColorIO.h>
#include <OpenColorIO/OpenColorABI.h>
#include <OpenColorIO/OpenColorTypes.h>
#include <OpenColorIO/OpenColorTransforms.h>

#include <istream>

BBL_MODULE(ocio) {

    bbl::fn(&OCIO_NAMESPACE::ClearAllCaches);

    bbl::fn(&OCIO_NAMESPACE::GetVersion);
    bbl::fn(&OCIO_NAMESPACE::GetVersionHex);

    bbl::fn(&OCIO_NAMESPACE::GetLoggingLevel);
    bbl::fn(&OCIO_NAMESPACE::SetLoggingLevel);
    bbl::fn(&OCIO_NAMESPACE::SetLoggingFunction);
    bbl::fn(&OCIO_NAMESPACE::ResetToDefaultLoggingFunction);
    bbl::fn(&OCIO_NAMESPACE::LogMessage);

    bbl::fn(&OCIO_NAMESPACE::SetComputeHashFunction);
    bbl::fn(&OCIO_NAMESPACE::ResetComputeHashFunction);

    bbl::fn(&OCIO_NAMESPACE::GetEnvVariable);
    bbl::fn(&OCIO_NAMESPACE::SetEnvVariable);
    bbl::fn(&OCIO_NAMESPACE::UnsetEnvVariable);
    bbl::fn(&OCIO_NAMESPACE::IsEnvVariablePresent);

    bbl::fn(&OCIO_NAMESPACE::GetCurrentConfig);
    bbl::fn(&OCIO_NAMESPACE::SetCurrentConfig);

    bbl::Enum<OCIO_NAMESPACE::Allocation>().prefix("");

    bbl::Enum<OCIO_NAMESPACE::LoggingLevel>().prefix("");

    bbl::Class<OCIO_NAMESPACE::LoggingFunction>();
    bbl::Class<OCIO_NAMESPACE::ComputeHashFunction>();

    bbl::Class<OCIO_NAMESPACE::Baker>()
        .m(&OCIO_NAMESPACE::Baker::Create)
        .m(&OCIO_NAMESPACE::Baker::createEditableCopy)
        .m(&OCIO_NAMESPACE::Baker::getConfig)
        .m(&OCIO_NAMESPACE::Baker::setConfig)
        .m(&OCIO_NAMESPACE::Baker::getFormat)
        .m(&OCIO_NAMESPACE::Baker::setFormat)
        .m((OCIO_NAMESPACE::FormatMetadata& (OCIO_NAMESPACE::Baker::*)())
            &OCIO_NAMESPACE::Baker::getFormatMetadata)
        .m((OCIO_NAMESPACE::FormatMetadata const& (OCIO_NAMESPACE::Baker::*)() const)
            &OCIO_NAMESPACE::Baker::getFormatMetadata, "getFormatMetadata_const")
        .m(&OCIO_NAMESPACE::Baker::getInputSpace)
        .m(&OCIO_NAMESPACE::Baker::setInputSpace)
        .m(&OCIO_NAMESPACE::Baker::getShaperSpace)
        .m(&OCIO_NAMESPACE::Baker::setShaperSpace)
        .m(&OCIO_NAMESPACE::Baker::getLooks)
        .m(&OCIO_NAMESPACE::Baker::setLooks)
        .m(&OCIO_NAMESPACE::Baker::getTargetSpace)
        .m(&OCIO_NAMESPACE::Baker::setTargetSpace)
        .m(&OCIO_NAMESPACE::Baker::getDisplay)
        .m(&OCIO_NAMESPACE::Baker::getView)
        .m(&OCIO_NAMESPACE::Baker::setDisplayView)
        .m(&OCIO_NAMESPACE::Baker::getShaperSize)
        .m(&OCIO_NAMESPACE::Baker::setShaperSize)
        .m(&OCIO_NAMESPACE::Baker::getCubeSize)
        .m(&OCIO_NAMESPACE::Baker::setCubeSize)
        // .m(&OCIO_NAMESPACE::Baker::bake)
        .m(&OCIO_NAMESPACE::Baker::getNumFormats)
        .m(&OCIO_NAMESPACE::Baker::getFormatNameByIndex)
        .m(&OCIO_NAMESPACE::Baker::getFormatExtensionByIndex)
        ;

    bbl::Class<OCIO_NAMESPACE::BakerRcPtr>("BakerRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Baker>()
        .m(&OCIO_NAMESPACE::BakerRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstBakerRcPtr>("ConstBakerRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Baker const>()
        .m(&OCIO_NAMESPACE::ConstBakerRcPtr::get)
        ;

    bbl::Enum<OCIO_NAMESPACE::BitDepth>().prefix("");


    bbl::Class<OCIO_NAMESPACE::BuiltinTransformRegistry>()
        .m(&OCIO_NAMESPACE::BuiltinTransformRegistry::Get)
        .m(&OCIO_NAMESPACE::BuiltinTransformRegistry::getNumBuiltins)
        .m(&OCIO_NAMESPACE::BuiltinTransformRegistry::getBuiltinStyle)
        .m(&OCIO_NAMESPACE::BuiltinTransformRegistry::getBuiltinDescription)
        ;

    bbl::Class<OCIO_NAMESPACE::BuiltinTransformRegistryRcPtr>("BuiltinTransformRegistryRcPtr")
        .smartptr_to<OCIO_NAMESPACE::BuiltinTransformRegistry>()
        .m(&OCIO_NAMESPACE::BuiltinTransformRegistryRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstBuiltinTransformRegistryRcPtr>("ConstBuiltinTransformRegistryRcPtr")
        .smartptr_to<OCIO_NAMESPACE::BuiltinTransformRegistry const>()
        .m(&OCIO_NAMESPACE::ConstBuiltinTransformRegistryRcPtr::get)
        ;

    bbl::Class<OCIO_NAMESPACE::BuiltinConfigRegistry>()
        .m(&OCIO_NAMESPACE::BuiltinConfigRegistry::Get)
        .m(&OCIO_NAMESPACE::BuiltinConfigRegistry::getNumBuiltinConfigs)
        .m(&OCIO_NAMESPACE::BuiltinConfigRegistry::getBuiltinConfigName)
        .m(&OCIO_NAMESPACE::BuiltinConfigRegistry::getBuiltinConfigUIName)
        .m(&OCIO_NAMESPACE::BuiltinConfigRegistry::getBuiltinConfig)
        .m(&OCIO_NAMESPACE::BuiltinConfigRegistry::getBuiltinConfigByName)
        .m(&OCIO_NAMESPACE::BuiltinConfigRegistry::isBuiltinConfigRecommended)
        .m(&OCIO_NAMESPACE::BuiltinConfigRegistry::getDefaultBuiltinConfigName)
        ;

    bbl::Enum<OCIO_NAMESPACE::ChannelOrdering>().prefix("");

    bbl::Enum<OCIO_NAMESPACE::ColorSpaceDirection>().prefix("");

    bbl::Class<OCIO_NAMESPACE::Config>()
        .m(&OCIO_NAMESPACE::Config::Create)
        .m(&OCIO_NAMESPACE::Config::CreateRaw)
        .m(&OCIO_NAMESPACE::Config::CreateFromEnv)
        .m(&OCIO_NAMESPACE::Config::CreateFromFile)
        .m(&OCIO_NAMESPACE::Config::CreateFromStream)
        .m(&OCIO_NAMESPACE::Config::CreateFromBuiltinConfig)
        .m(&OCIO_NAMESPACE::Config::createEditableCopy)
        .m(&OCIO_NAMESPACE::Config::getMajorVersion)
        .m(&OCIO_NAMESPACE::Config::setMajorVersion)
        .m(&OCIO_NAMESPACE::Config::getMinorVersion)
        .m(&OCIO_NAMESPACE::Config::setMinorVersion)
        .m(&OCIO_NAMESPACE::Config::setVersion)
        .m(&OCIO_NAMESPACE::Config::upgradeToLatestVersion)
        .m(&OCIO_NAMESPACE::Config::validate)
        .m(&OCIO_NAMESPACE::Config::getName)
        .m(&OCIO_NAMESPACE::Config::setName)
        .m(&OCIO_NAMESPACE::Config::getFamilySeparator)
        .m(&OCIO_NAMESPACE::Config::setFamilySeparator)
        .m(&OCIO_NAMESPACE::Config::GetDefaultFamilySeparator)
        .m(&OCIO_NAMESPACE::Config::getDescription)
        .m(&OCIO_NAMESPACE::Config::setDescription)
        .m((char const* (OCIO_NAMESPACE::Config::*)() const)
            &OCIO_NAMESPACE::Config::getCacheID)
        .m((char const* (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::ConstContextRcPtr const&) const)
            &OCIO_NAMESPACE::Config::getCacheID, "getCacheID_from_context")
        .m(&OCIO_NAMESPACE::Config::getCurrentContext)
        .m(&OCIO_NAMESPACE::Config::addEnvironmentVar)
        .m(&OCIO_NAMESPACE::Config::getNumEnvironmentVars)
        .m(&OCIO_NAMESPACE::Config::getEnvironmentVarNameByIndex)
        .m(&OCIO_NAMESPACE::Config::getEnvironmentVarDefault)
        .m(&OCIO_NAMESPACE::Config::clearEnvironmentVars)
        .m(&OCIO_NAMESPACE::Config::setEnvironmentMode)
        .m(&OCIO_NAMESPACE::Config::getEnvironmentMode)
        .m(&OCIO_NAMESPACE::Config::loadEnvironment)
        .m((char const* (OCIO_NAMESPACE::Config::*)() const)
            &OCIO_NAMESPACE::Config::getSearchPath)
        .m((char const* (OCIO_NAMESPACE::Config::*)(int) const)
            &OCIO_NAMESPACE::Config::getSearchPath, "getSearchPath_by_index")
        .m(&OCIO_NAMESPACE::Config::setSearchPath)
        .m(&OCIO_NAMESPACE::Config::getNumSearchPaths)
        .m(&OCIO_NAMESPACE::Config::clearSearchPaths)
        .m(&OCIO_NAMESPACE::Config::addSearchPath)
        .m(&OCIO_NAMESPACE::Config::getWorkingDir)
        .m(&OCIO_NAMESPACE::Config::setWorkingDir)
        .m((int (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::SearchReferenceSpaceType, OCIO_NAMESPACE::ColorSpaceVisibility) const)
            &OCIO_NAMESPACE::Config::getNumColorSpaces, "getNumColorSpaces_matching")
        .m((int (OCIO_NAMESPACE::Config::*)() const)
            &OCIO_NAMESPACE::Config::getNumColorSpaces)
        .m((char const* (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::SearchReferenceSpaceType, OCIO_NAMESPACE::ColorSpaceVisibility, int) const)
            &OCIO_NAMESPACE::Config::getColorSpaceNameByIndex, "getColorSpaceNameByIndex_matching")
        .m((char const* (OCIO_NAMESPACE::Config::*)(int) const)
            &OCIO_NAMESPACE::Config::getColorSpaceNameByIndex)
        .m(&OCIO_NAMESPACE::Config::getColorSpaces)
        .m(&OCIO_NAMESPACE::Config::getIndexForColorSpace)
        .m(&OCIO_NAMESPACE::Config::getColorSpace)
        .m(&OCIO_NAMESPACE::Config::getCanonicalName)
        .m(&OCIO_NAMESPACE::Config::addColorSpace)
        .m(&OCIO_NAMESPACE::Config::removeColorSpace)
        .m(&OCIO_NAMESPACE::Config::clearColorSpaces)
        .m(&OCIO_NAMESPACE::Config::getInactiveColorSpaces)
        .m(&OCIO_NAMESPACE::Config::setInactiveColorSpaces)
        .m(&OCIO_NAMESPACE::Config::isColorSpaceUsed)
        .m(&OCIO_NAMESPACE::Config::setRole)
        .m(&OCIO_NAMESPACE::Config::getNumRoles)
        .m(&OCIO_NAMESPACE::Config::hasRole)
        .m(&OCIO_NAMESPACE::Config::getRoleName)
        .m(&OCIO_NAMESPACE::Config::getRoleColorSpace)
        .m(&OCIO_NAMESPACE::Config::addSharedView)
        .m(&OCIO_NAMESPACE::Config::removeSharedView)
        .m(&OCIO_NAMESPACE::Config::getDefaultDisplay)
        .m(&OCIO_NAMESPACE::Config::getNumDisplays)
        .m(&OCIO_NAMESPACE::Config::getDisplay)
        .m((char const* (OCIO_NAMESPACE::Config::*)(char const*) const)
            &OCIO_NAMESPACE::Config::getDefaultView)
        .m((char const* (OCIO_NAMESPACE::Config::*)(char const*, char const*) const)
            &OCIO_NAMESPACE::Config::getDefaultView, "getDefaultView_for_colorspace")
        .m((int (OCIO_NAMESPACE::Config::*)(char const*) const)
            &OCIO_NAMESPACE::Config::getNumViews)
        .m((int (OCIO_NAMESPACE::Config::*)(char const*, char const*) const)
            &OCIO_NAMESPACE::Config::getNumViews, "getNumViews_for_colorspace")
        .m((char const* (OCIO_NAMESPACE::Config::*)(char const*, int) const)
            &OCIO_NAMESPACE::Config::getView)
        .m((char const* (OCIO_NAMESPACE::Config::*)(char const*, char const*, int) const)
            &OCIO_NAMESPACE::Config::getView, "getView_for_colorspace")
        .m(&OCIO_NAMESPACE::Config::getDisplayViewTransformName)
        .m(&OCIO_NAMESPACE::Config::getDisplayViewColorSpaceName)
        .m(&OCIO_NAMESPACE::Config::getDisplayViewLooks)
        .m(&OCIO_NAMESPACE::Config::getDisplayViewRule)
        .m(&OCIO_NAMESPACE::Config::getDisplayViewDescription)
        .m((void (OCIO_NAMESPACE::Config::*)(char const*, char const*, char const*, char const*))
            &OCIO_NAMESPACE::Config::addDisplayView)
        .m((void (OCIO_NAMESPACE::Config::*)(char const*, char const*, char const*, char const*, char const*, char const*, char const*))
            &OCIO_NAMESPACE::Config::addDisplayView, "addDisplayView2")
        .m(&OCIO_NAMESPACE::Config::addDisplaySharedView)
        .m(&OCIO_NAMESPACE::Config::removeDisplayView)
        .m(&OCIO_NAMESPACE::Config::clearDisplays)
        .m(&OCIO_NAMESPACE::Config::addVirtualDisplayView)
        .m(&OCIO_NAMESPACE::Config::addVirtualDisplaySharedView)
        .m(&OCIO_NAMESPACE::Config::getVirtualDisplayNumViews)
        .m(&OCIO_NAMESPACE::Config::getVirtualDisplayView)
        .m(&OCIO_NAMESPACE::Config::getVirtualDisplayViewTransformName)
        .m(&OCIO_NAMESPACE::Config::getVirtualDisplayViewColorSpaceName)
        .m(&OCIO_NAMESPACE::Config::getVirtualDisplayViewLooks)
        .m(&OCIO_NAMESPACE::Config::getVirtualDisplayViewRule)
        .m(&OCIO_NAMESPACE::Config::getVirtualDisplayViewDescription)
        .m(&OCIO_NAMESPACE::Config::removeVirtualDisplayView)
        .m(&OCIO_NAMESPACE::Config::instantiateDisplayFromMonitorName)
        .m(&OCIO_NAMESPACE::Config::instantiateDisplayFromICCProfile)
        .m(&OCIO_NAMESPACE::Config::setActiveDisplays)
        .m(&OCIO_NAMESPACE::Config::getActiveDisplays)
        .m(&OCIO_NAMESPACE::Config::setActiveViews)
        .m(&OCIO_NAMESPACE::Config::getActiveViews)
        .m(&OCIO_NAMESPACE::Config::getNumDisplaysAll)
        .m(&OCIO_NAMESPACE::Config::getDisplayAll)
        .m(&OCIO_NAMESPACE::Config::getDisplayAllByName)
        .m(&OCIO_NAMESPACE::Config::isDisplayTemporary)
        .m((int (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::ViewType, char const*) const)
            &OCIO_NAMESPACE::Config::getNumViews, "getNumViews_for_display")
        .m((char const* (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::ViewType, char const*, int) const)
            &OCIO_NAMESPACE::Config::getView, "getView_for_display")
        .m(&OCIO_NAMESPACE::Config::getViewingRules)
        .m(&OCIO_NAMESPACE::Config::setViewingRules)
        .m(&OCIO_NAMESPACE::Config::getDefaultLumaCoefs)
        .m(&OCIO_NAMESPACE::Config::setDefaultLumaCoefs)

        .m(&OCIO_NAMESPACE::Config::getLook)
        .m(&OCIO_NAMESPACE::Config::getNumLooks)
        .m(&OCIO_NAMESPACE::Config::getLookNameByIndex)
        .m(&OCIO_NAMESPACE::Config::addLook)
        .m(&OCIO_NAMESPACE::Config::clearLooks)

        .m(&OCIO_NAMESPACE::Config::getNumViewTransforms)
        .m(&OCIO_NAMESPACE::Config::getViewTransform)
        .m(&OCIO_NAMESPACE::Config::getViewTransformNameByIndex)
        .m(&OCIO_NAMESPACE::Config::addViewTransform)

        .m(&OCIO_NAMESPACE::Config::getDefaultSceneToDisplayViewTransform)
        .m(&OCIO_NAMESPACE::Config::getDefaultViewTransformName)
        .m(&OCIO_NAMESPACE::Config::setDefaultViewTransformName)
        .m(&OCIO_NAMESPACE::Config::clearViewTransforms)

        .m((int (OCIO_NAMESPACE::Config::*)() const)
            &OCIO_NAMESPACE::Config::getNumNamedTransforms)
        .m((int (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::NamedTransformVisibility) const)
            &OCIO_NAMESPACE::Config::getNumNamedTransforms, "getNumNamedTransforms_by_visibility")

        .m((char const* (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::NamedTransformVisibility, int) const)
            &OCIO_NAMESPACE::Config::getNamedTransformNameByIndex)
        .m((char const* (OCIO_NAMESPACE::Config::*)(int) const)
            &OCIO_NAMESPACE::Config::getNamedTransformNameByIndex, "getNamedTransformNameByIndex_and_visibility")

        .m(&OCIO_NAMESPACE::Config::getIndexForNamedTransform)
        .m(&OCIO_NAMESPACE::Config::getNamedTransform)
        .m(&OCIO_NAMESPACE::Config::addNamedTransform)
        .m(&OCIO_NAMESPACE::Config::clearNamedTransforms)

        .m(&OCIO_NAMESPACE::Config::getFileRules)
        .m(&OCIO_NAMESPACE::Config::setFileRules)

        .m((char const* (OCIO_NAMESPACE::Config::*)(char const*) const)
            &OCIO_NAMESPACE::Config::getColorSpaceFromFilepath)
        .m((char const* (OCIO_NAMESPACE::Config::*)(char const*, size_t&) const)
            &OCIO_NAMESPACE::Config::getColorSpaceFromFilepath, "getColorSpaceFromFilepath_with_rule_index")

        .m(&OCIO_NAMESPACE::Config::filepathOnlyMatchesDefaultRule)

        .m(&OCIO_NAMESPACE::Config::isStrictParsingEnabled)
        .m(&OCIO_NAMESPACE::Config::setStrictParsingEnabled)

        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::ConstContextRcPtr const&, OCIO_NAMESPACE::ConstColorSpaceRcPtr const&, OCIO_NAMESPACE::ConstColorSpaceRcPtr const&) const)
            &OCIO_NAMESPACE::Config::getProcessor, "getProcessor_from_context")
        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::ConstColorSpaceRcPtr const&, OCIO_NAMESPACE::ConstColorSpaceRcPtr const&) const)
            &OCIO_NAMESPACE::Config::getProcessor, "getProcessor")

        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::ConstContextRcPtr const&, char const*, char const*) const)
            &OCIO_NAMESPACE::Config::getProcessor, "getProcessor_by_name_from_context")
        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (OCIO_NAMESPACE::Config::*)(char const*, char const*) const)
            &OCIO_NAMESPACE::Config::getProcessor, "getProcessor_by_name")

        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::ConstContextRcPtr const&, char const*, char const*, char const*, OCIO_NAMESPACE::TransformDirection) const)
            &OCIO_NAMESPACE::Config::getProcessor, "getProcessor_for_display_and_view_from_context")
        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (OCIO_NAMESPACE::Config::*)(char const*, char const*, char const*, OCIO_NAMESPACE::TransformDirection) const)
            &OCIO_NAMESPACE::Config::getProcessor, "getProcessor_for_display_and_view")

        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::ConstTransformRcPtr const&, OCIO_NAMESPACE::TransformDirection) const)
            &OCIO_NAMESPACE::Config::getProcessor, "getProcessor_for_transform")
        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (OCIO_NAMESPACE::Config::*)(OCIO_NAMESPACE::ConstContextRcPtr const&, OCIO_NAMESPACE::ConstTransformRcPtr const&, OCIO_NAMESPACE::TransformDirection) const)
            &OCIO_NAMESPACE::Config::getProcessor, "getProcessor_for_transform_from_context")

        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (*)(OCIO_NAMESPACE::ConstConfigRcPtr const&, char const*, OCIO_NAMESPACE::ConstConfigRcPtr const&, char const*))
            &OCIO_NAMESPACE::Config::GetProcessorFromConfigs, "GetProcessorFromConfigs")
        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (*)(OCIO_NAMESPACE::ConstContextRcPtr const&, OCIO_NAMESPACE::ConstConfigRcPtr const&, char const*, OCIO_NAMESPACE::ConstContextRcPtr const&, OCIO_NAMESPACE::ConstConfigRcPtr const&, char const*))
            &OCIO_NAMESPACE::Config::GetProcessorFromConfigs, "GetProcessorFromConfigs_with_context")

        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (*)(OCIO_NAMESPACE::ConstConfigRcPtr const&, char const*, char const*, OCIO_NAMESPACE::ConstConfigRcPtr const&, char const*, char const*))
            &OCIO_NAMESPACE::Config::GetProcessorFromConfigs, "GetProcessorFromConfigs_with_interchange")
        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (*)(OCIO_NAMESPACE::ConstContextRcPtr const&, OCIO_NAMESPACE::ConstConfigRcPtr const&, char const*, char const*, OCIO_NAMESPACE::ConstContextRcPtr const&, OCIO_NAMESPACE::ConstConfigRcPtr const&, char const*, char const*))
            &OCIO_NAMESPACE::Config::GetProcessorFromConfigs, "GetProcessorFromConfigs_with_interchange_and_context")

        .m(&OCIO_NAMESPACE::Config::setProcessorCacheFlags)
        ;

    bbl::Class<OCIO_NAMESPACE::ConfigRcPtr>("ConfigRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Config>()
        .m(&OCIO_NAMESPACE::ConfigRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstConfigRcPtr>("ConstConfigRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Config const>()
        .m(&OCIO_NAMESPACE::ConstConfigRcPtr::get)
        ;

    bbl::Class<OCIO_NAMESPACE::ColorSpace>()
        .m((OCIO_NAMESPACE::ColorSpaceRcPtr (*)())
            &OCIO_NAMESPACE::ColorSpace::Create)
        .m((OCIO_NAMESPACE::ColorSpaceRcPtr (*)(OCIO_NAMESPACE::ReferenceSpaceType))
            &OCIO_NAMESPACE::ColorSpace::Create, "Create_with_reference_space")
        .m(&OCIO_NAMESPACE::ColorSpace::createEditableCopy)
        .m(&OCIO_NAMESPACE::ColorSpace::getName)
        .m(&OCIO_NAMESPACE::ColorSpace::setName)
        .m(&OCIO_NAMESPACE::ColorSpace::getNumAliases)
        .m(&OCIO_NAMESPACE::ColorSpace::getAlias)
        .m(&OCIO_NAMESPACE::ColorSpace::addAlias)
        .m(&OCIO_NAMESPACE::ColorSpace::removeAlias)
        .m(&OCIO_NAMESPACE::ColorSpace::clearAliases)
        .m(&OCIO_NAMESPACE::ColorSpace::getFamily)
        .m(&OCIO_NAMESPACE::ColorSpace::setFamily)
        .m(&OCIO_NAMESPACE::ColorSpace::getEqualityGroup)
        .m(&OCIO_NAMESPACE::ColorSpace::setEqualityGroup)
        .m(&OCIO_NAMESPACE::ColorSpace::getDescription)
        .m(&OCIO_NAMESPACE::ColorSpace::setDescription)
        .m(&OCIO_NAMESPACE::ColorSpace::getBitDepth)
        .m(&OCIO_NAMESPACE::ColorSpace::setBitDepth)
        .m(&OCIO_NAMESPACE::ColorSpace::getReferenceSpaceType)
        .m(&OCIO_NAMESPACE::ColorSpace::hasCategory)
        .m(&OCIO_NAMESPACE::ColorSpace::addCategory)
        .m(&OCIO_NAMESPACE::ColorSpace::removeCategory)
        .m(&OCIO_NAMESPACE::ColorSpace::getNumCategories)
        .m(&OCIO_NAMESPACE::ColorSpace::getCategory)
        .m(&OCIO_NAMESPACE::ColorSpace::clearCategories)
        .m(&OCIO_NAMESPACE::ColorSpace::getEncoding)
        .m(&OCIO_NAMESPACE::ColorSpace::setEncoding)
        .m(&OCIO_NAMESPACE::ColorSpace::isData)
        .m(&OCIO_NAMESPACE::ColorSpace::setIsData)
        .m(&OCIO_NAMESPACE::ColorSpace::getAllocation)
        .m(&OCIO_NAMESPACE::ColorSpace::setAllocation)
        .m(&OCIO_NAMESPACE::ColorSpace::getAllocationNumVars)
        .m(&OCIO_NAMESPACE::ColorSpace::getAllocationVars)
        .m(&OCIO_NAMESPACE::ColorSpace::setAllocationVars)
        .m(&OCIO_NAMESPACE::ColorSpace::getTransform)
        .m(&OCIO_NAMESPACE::ColorSpace::setTransform)
        ;

    bbl::Class<OCIO_NAMESPACE::ColorSpaceRcPtr>("ColorSpaceRcPtr")
        .smartptr_to<OCIO_NAMESPACE::ColorSpace>()
        .m(&OCIO_NAMESPACE::ColorSpaceRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstColorSpaceRcPtr>("ConstColorSpaceRcPtr")
        .smartptr_to<OCIO_NAMESPACE::ColorSpace const>()
        .m(&OCIO_NAMESPACE::ConstColorSpaceRcPtr::get)
        ;
        
    bbl::Class<OCIO_NAMESPACE::ColorSpaceSet>()
        .m(&OCIO_NAMESPACE::ColorSpaceSet::Create)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::createEditableCopy)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::getNumColorSpaces)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::getColorSpaceNameByIndex)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::getColorSpaceByIndex)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::getColorSpace)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::getColorSpaceIndex)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::hasColorSpace)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::addColorSpace)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::addColorSpaces)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::removeColorSpace)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::removeColorSpaces)
        .m(&OCIO_NAMESPACE::ColorSpaceSet::clearColorSpaces)
        ;

    bbl::Class<OCIO_NAMESPACE::ColorSpaceSetRcPtr>("ColorSpaceSetRcPtr")
        .smartptr_to<OCIO_NAMESPACE::ColorSpaceSet>()
        .m(&OCIO_NAMESPACE::ColorSpaceSetRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstColorSpaceSetRcPtr>("ConstColorSpaceSetRcPtr")
        .smartptr_to<OCIO_NAMESPACE::ColorSpaceSet const>()
        .m(&OCIO_NAMESPACE::ConstColorSpaceSetRcPtr::get)
        ;

    bbl::fn(&OCIO_NAMESPACE::operator||, "colorspaceset_union");
    bbl::fn(&OCIO_NAMESPACE::operator&&, "colorspaceset_intersection");
    bbl::fn(&OCIO_NAMESPACE::operator-, "colorspaceset_difference");
        
    bbl::Enum<OCIO_NAMESPACE::ColorSpaceVisibility>().prefix("");

    bbl::Class<OCIO_NAMESPACE::Context>()
        .m(&OCIO_NAMESPACE::Context::Create)
        .m(&OCIO_NAMESPACE::Context::createEditableCopy)
        .m(&OCIO_NAMESPACE::Context::getCacheID)
        .m((char const* (OCIO_NAMESPACE::Context::*)() const)
            &OCIO_NAMESPACE::Context::getSearchPath)
        .m((char const* (OCIO_NAMESPACE::Context::*)(int) const)
            &OCIO_NAMESPACE::Context::getSearchPath, "getSearchPath_by_index")
        .m(&OCIO_NAMESPACE::Context::setSearchPath)
        .m(&OCIO_NAMESPACE::Context::getNumSearchPaths)
        .m(&OCIO_NAMESPACE::Context::clearSearchPaths)
        .m(&OCIO_NAMESPACE::Context::addSearchPath)
        .m(&OCIO_NAMESPACE::Context::getWorkingDir)
        .m(&OCIO_NAMESPACE::Context::setWorkingDir)
        .m(&OCIO_NAMESPACE::Context::setStringVar)
        .m(&OCIO_NAMESPACE::Context::getNumStringVars)
        .m(&OCIO_NAMESPACE::Context::getStringVarNameByIndex)
        .m(&OCIO_NAMESPACE::Context::getStringVarByIndex)
        .m(&OCIO_NAMESPACE::Context::clearStringVars)
        .m(&OCIO_NAMESPACE::Context::addStringVars)
        .m(&OCIO_NAMESPACE::Context::setEnvironmentMode)
        .m(&OCIO_NAMESPACE::Context::getEnvironmentMode)
        .m(&OCIO_NAMESPACE::Context::loadEnvironment)
        .m((char const* (OCIO_NAMESPACE::Context::*)(char const*) const)
            &OCIO_NAMESPACE::Context::resolveStringVar)
        .m((char const* (OCIO_NAMESPACE::Context::*)(char const*, OCIO_NAMESPACE::ContextRcPtr&) const)
            &OCIO_NAMESPACE::Context::resolveStringVar, "resolveStringVar_with_used")
        .m((char const* (OCIO_NAMESPACE::Context::*)(char const*) const)
            &OCIO_NAMESPACE::Context::resolveFileLocation)
        .m((char const* (OCIO_NAMESPACE::Context::*)(char const*, OCIO_NAMESPACE::ContextRcPtr&) const)
            &OCIO_NAMESPACE::Context::resolveFileLocation, "resolveFileLocation_with_used")
        ;

    bbl::Class<OCIO_NAMESPACE::ContextRcPtr>("ContextRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Context>()
        .m(&OCIO_NAMESPACE::ContextRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstContextRcPtr>("ConstContextRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Context const>()
        .m(&OCIO_NAMESPACE::ConstContextRcPtr::get)
        ;

    bbl::Class<OCIO_NAMESPACE::FileRules>()
        .m(&OCIO_NAMESPACE::FileRules::Create)
        .m(&OCIO_NAMESPACE::FileRules::createEditableCopy)
        .m(&OCIO_NAMESPACE::FileRules::getNumEntries)
        .m(&OCIO_NAMESPACE::FileRules::getIndexForRule)
        .m(&OCIO_NAMESPACE::FileRules::getName)
        .m(&OCIO_NAMESPACE::FileRules::getPattern)
        .m(&OCIO_NAMESPACE::FileRules::setPattern)
        .m(&OCIO_NAMESPACE::FileRules::getExtension)
        .m(&OCIO_NAMESPACE::FileRules::setExtension)
        .m(&OCIO_NAMESPACE::FileRules::getRegex)
        .m(&OCIO_NAMESPACE::FileRules::setRegex)
        .m(&OCIO_NAMESPACE::FileRules::getColorSpace)
        .m(&OCIO_NAMESPACE::FileRules::setColorSpace)
        .m(&OCIO_NAMESPACE::FileRules::getNumCustomKeys)
        .m(&OCIO_NAMESPACE::FileRules::getCustomKeyName)
        .m(&OCIO_NAMESPACE::FileRules::getCustomKeyValue)
        .m((void (OCIO_NAMESPACE::FileRules::*)(size_t, char const*, char const*, char const*, char const*))
            &OCIO_NAMESPACE::FileRules::insertRule)
        .m((void (OCIO_NAMESPACE::FileRules::*)(size_t, char const*, char const*, char const*))
            &OCIO_NAMESPACE::FileRules::insertRule, "insertRule_regex")

        .m(&OCIO_NAMESPACE::FileRules::insertPathSearchRule)
        .m(&OCIO_NAMESPACE::FileRules::setDefaultRuleColorSpace)
        .m(&OCIO_NAMESPACE::FileRules::removeRule)
        .m(&OCIO_NAMESPACE::FileRules::increaseRulePriority)
        .m(&OCIO_NAMESPACE::FileRules::decreaseRulePriority)
        .m(&OCIO_NAMESPACE::FileRules::isDefault)
        ;

    bbl::Class<OCIO_NAMESPACE::FileRulesRcPtr>("FileRulesRcPtr")
        .smartptr_to<OCIO_NAMESPACE::FileRules>()
        .m(&OCIO_NAMESPACE::FileRulesRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstFileRulesRcPtr>("ConstFileRulesRcPtr")
        .smartptr_to<OCIO_NAMESPACE::FileRules const>()
        .m(&OCIO_NAMESPACE::ConstFileRulesRcPtr::get)
        ;

    bbl::Enum<OCIO_NAMESPACE::GpuLanguage>().prefix("");
    
    bbl::Class<OCIO_NAMESPACE::ImageDesc>()
        .m(&OCIO_NAMESPACE::ImageDesc::getRData)
        .m(&OCIO_NAMESPACE::ImageDesc::getGData)
        .m(&OCIO_NAMESPACE::ImageDesc::getBData)
        .m(&OCIO_NAMESPACE::ImageDesc::getAData)
        .m(&OCIO_NAMESPACE::ImageDesc::getBitDepth)
        .m(&OCIO_NAMESPACE::ImageDesc::getWidth)
        .m(&OCIO_NAMESPACE::ImageDesc::getHeight)
        .m(&OCIO_NAMESPACE::ImageDesc::getXStrideBytes)
        .m(&OCIO_NAMESPACE::ImageDesc::getYStrideBytes)
        .m(&OCIO_NAMESPACE::ImageDesc::isRGBAPacked)
        .m(&OCIO_NAMESPACE::ImageDesc::isFloat)
        ;

    bbl::Enum<OCIO_NAMESPACE::Interpolation>().prefix("");

    bbl::Class<OCIO_NAMESPACE::Look>()
        .m(&OCIO_NAMESPACE::Look::Create)
        .m(&OCIO_NAMESPACE::Look::createEditableCopy)
        .m(&OCIO_NAMESPACE::Look::getName)
        .m(&OCIO_NAMESPACE::Look::setName)
        .m(&OCIO_NAMESPACE::Look::getProcessSpace)
        .m(&OCIO_NAMESPACE::Look::setProcessSpace)
        .m(&OCIO_NAMESPACE::Look::getTransform)
        .m(&OCIO_NAMESPACE::Look::setTransform)
        .m(&OCIO_NAMESPACE::Look::getInverseTransform)
        .m(&OCIO_NAMESPACE::Look::setInverseTransform)
        .m(&OCIO_NAMESPACE::Look::getDescription)
        .m(&OCIO_NAMESPACE::Look::setDescription)
        ;

    bbl::Class<OCIO_NAMESPACE::LookRcPtr>("LookRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Look>()
        .m(&OCIO_NAMESPACE::LookRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstLookRcPtr>("ConstLookRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Look const>()
        .m(&OCIO_NAMESPACE::ConstLookRcPtr::get)
        ;

    bbl::Class<OCIO_NAMESPACE::NamedTransform>()
        .m(&OCIO_NAMESPACE::NamedTransform::Create)
        .m(&OCIO_NAMESPACE::NamedTransform::createEditableCopy)
        .m(&OCIO_NAMESPACE::NamedTransform::getName)
        .m(&OCIO_NAMESPACE::NamedTransform::setName)
        .m(&OCIO_NAMESPACE::NamedTransform::getNumAliases)
        .m(&OCIO_NAMESPACE::NamedTransform::getAlias)
        .m(&OCIO_NAMESPACE::NamedTransform::addAlias)
        .m(&OCIO_NAMESPACE::NamedTransform::removeAlias)
        .m(&OCIO_NAMESPACE::NamedTransform::clearAliases)
        .m(&OCIO_NAMESPACE::NamedTransform::getFamily)
        .m(&OCIO_NAMESPACE::NamedTransform::setFamily)
        .m(&OCIO_NAMESPACE::NamedTransform::getDescription)
        .m(&OCIO_NAMESPACE::NamedTransform::setDescription)
        .m(&OCIO_NAMESPACE::NamedTransform::hasCategory)
        .m(&OCIO_NAMESPACE::NamedTransform::addCategory)
        .m(&OCIO_NAMESPACE::NamedTransform::removeCategory)
        .m(&OCIO_NAMESPACE::NamedTransform::getNumCategories)
        .m(&OCIO_NAMESPACE::NamedTransform::getCategory)
        .m(&OCIO_NAMESPACE::NamedTransform::clearCategories)
        .m(&OCIO_NAMESPACE::NamedTransform::getEncoding)
        .m(&OCIO_NAMESPACE::NamedTransform::setEncoding)
        .m(&OCIO_NAMESPACE::NamedTransform::getTransform)
        .m(&OCIO_NAMESPACE::NamedTransform::setTransform)
        ;

    bbl::Class<OCIO_NAMESPACE::NamedTransformRcPtr>("NamedTransformRcPtr")
        .smartptr_to<OCIO_NAMESPACE::NamedTransform>()
        .m(&OCIO_NAMESPACE::NamedTransformRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstNamedTransformRcPtr>("ConstNamedTransformRcPtr")
        .smartptr_to<OCIO_NAMESPACE::NamedTransform const>()
        .m(&OCIO_NAMESPACE::ConstNamedTransformRcPtr::get)
        ;

    bbl::Enum<OCIO_NAMESPACE::NamedTransformVisibility>().prefix("");

    bbl::Enum<OCIO_NAMESPACE::EnvironmentMode>().prefix("");

    bbl::Class<OCIO_NAMESPACE::PackedImageDesc>()
        .ctor(bbl::Class<OCIO_NAMESPACE::PackedImageDesc>::Ctor<void*, long, long, OCIO_NAMESPACE::ChannelOrdering, OCIO_NAMESPACE::BitDepth, ptrdiff_t, ptrdiff_t, ptrdiff_t>
                                                         ("data", "width", "height", "channelOrdering", "bitDepth", "chanStrideBytes", "xStrideBytes", "yStrideBytes"))
        .m(&OCIO_NAMESPACE::PackedImageDesc::getRData)
        .m(&OCIO_NAMESPACE::PackedImageDesc::getGData)
        .m(&OCIO_NAMESPACE::PackedImageDesc::getBData)
        .m(&OCIO_NAMESPACE::PackedImageDesc::getAData)
        .m(&OCIO_NAMESPACE::PackedImageDesc::getBitDepth)
        .m(&OCIO_NAMESPACE::PackedImageDesc::getWidth)
        .m(&OCIO_NAMESPACE::PackedImageDesc::getHeight)
        .m(&OCIO_NAMESPACE::PackedImageDesc::getXStrideBytes)
        .m(&OCIO_NAMESPACE::PackedImageDesc::getYStrideBytes)
        .m(&OCIO_NAMESPACE::PackedImageDesc::isRGBAPacked)
        .m(&OCIO_NAMESPACE::PackedImageDesc::isFloat)
        ;


    bbl::Class<OCIO_NAMESPACE::PlanarImageDesc>()
        .ctor(bbl::Class<OCIO_NAMESPACE::PlanarImageDesc>::Ctor<void*, void*, void*, void*, long, long, OCIO_NAMESPACE::BitDepth, ptrdiff_t, ptrdiff_t>
                                                         ("rData", "gData", "bData", "aData", "width", "height", "bitDepth", "xStrideBytes", "yStrideBytes"))
        .m(&OCIO_NAMESPACE::PlanarImageDesc::getRData)
        .m(&OCIO_NAMESPACE::PlanarImageDesc::getGData)
        .m(&OCIO_NAMESPACE::PlanarImageDesc::getBData)
        .m(&OCIO_NAMESPACE::PlanarImageDesc::getAData)
        .m(&OCIO_NAMESPACE::PlanarImageDesc::getBitDepth)
        .m(&OCIO_NAMESPACE::PlanarImageDesc::getWidth)
        .m(&OCIO_NAMESPACE::PlanarImageDesc::getHeight)
        .m(&OCIO_NAMESPACE::PlanarImageDesc::getXStrideBytes)
        .m(&OCIO_NAMESPACE::PlanarImageDesc::getYStrideBytes)
        .m(&OCIO_NAMESPACE::PlanarImageDesc::isRGBAPacked)
        .m(&OCIO_NAMESPACE::PlanarImageDesc::isFloat)
        ;


    bbl::Class<OCIO_NAMESPACE::Processor>()
        .m(&OCIO_NAMESPACE::Processor::isNoOp)
        .m(&OCIO_NAMESPACE::Processor::hasChannelCrosstalk)
        .m(&OCIO_NAMESPACE::Processor::getCacheID)
        .m(&OCIO_NAMESPACE::Processor::getProcessorMetadata)
        .m(&OCIO_NAMESPACE::Processor::getFormatMetadata)
        .m(&OCIO_NAMESPACE::Processor::getNumTransforms)
        .m(&OCIO_NAMESPACE::Processor::getTransformFormatMetadata)
        .m(&OCIO_NAMESPACE::Processor::createGroupTransform)
        .m(&OCIO_NAMESPACE::Processor::getDynamicProperty)
        .m(&OCIO_NAMESPACE::Processor::hasDynamicProperty)
        .m(&OCIO_NAMESPACE::Processor::isDynamic)
        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (OCIO_NAMESPACE::Processor::*)(OCIO_NAMESPACE::OptimizationFlags) const)
            &OCIO_NAMESPACE::Processor::getOptimizedProcessor)
        .m((OCIO_NAMESPACE::ConstProcessorRcPtr (OCIO_NAMESPACE::Processor::*)(OCIO_NAMESPACE::BitDepth, OCIO_NAMESPACE::BitDepth, OCIO_NAMESPACE::OptimizationFlags) const)
            &OCIO_NAMESPACE::Processor::getOptimizedProcessor, "getOptimizedProcessor_with_bit_depth")
        .m(&OCIO_NAMESPACE::Processor::getDefaultGPUProcessor)
        .m(&OCIO_NAMESPACE::Processor::getOptimizedGPUProcessor)
        .m(&OCIO_NAMESPACE::Processor::getOptimizedLegacyGPUProcessor)
        .m(&OCIO_NAMESPACE::Processor::getDefaultCPUProcessor)
        .m((OCIO_NAMESPACE::ConstCPUProcessorRcPtr (OCIO_NAMESPACE::Processor::*)(OCIO_NAMESPACE::OptimizationFlags) const)
            &OCIO_NAMESPACE::Processor::getOptimizedCPUProcessor)
        .m((OCIO_NAMESPACE::ConstCPUProcessorRcPtr (OCIO_NAMESPACE::Processor::*)(OCIO_NAMESPACE::BitDepth, OCIO_NAMESPACE::BitDepth, OCIO_NAMESPACE::OptimizationFlags) const)
            &OCIO_NAMESPACE::Processor::getOptimizedCPUProcessor, "getOptimizedCPUProcessor_with_bit_depth")
        ;

    bbl::Class<OCIO_NAMESPACE::ProcessorRcPtr>("ProcessorRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Processor>()
        .m(&OCIO_NAMESPACE::ProcessorRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstProcessorRcPtr>("ConstProcessorRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Processor const>()
        .m(&OCIO_NAMESPACE::ConstProcessorRcPtr::get)
        ;

    bbl::Class<OCIO_NAMESPACE::CPUProcessor>()
        .m(&OCIO_NAMESPACE::CPUProcessor::isNoOp)
        .m(&OCIO_NAMESPACE::CPUProcessor::isIdentity)
        .m(&OCIO_NAMESPACE::CPUProcessor::hasChannelCrosstalk)
        .m(&OCIO_NAMESPACE::CPUProcessor::getCacheID)
        .m(&OCIO_NAMESPACE::CPUProcessor::getInputBitDepth)
        .m(&OCIO_NAMESPACE::CPUProcessor::getOutputBitDepth)
        .m((void (OCIO_NAMESPACE::CPUProcessor::*)(OCIO_NAMESPACE::ImageDesc&) const)
            &OCIO_NAMESPACE::CPUProcessor::apply, "apply_in_place")
        .m((void (OCIO_NAMESPACE::CPUProcessor::*)(OCIO_NAMESPACE::ImageDesc const&, OCIO_NAMESPACE::ImageDesc&) const)
            &OCIO_NAMESPACE::CPUProcessor::apply)
        .m(&OCIO_NAMESPACE::CPUProcessor::getDynamicProperty)
        .m(&OCIO_NAMESPACE::CPUProcessor::applyRGB)
        .m(&OCIO_NAMESPACE::CPUProcessor::applyRGBA)
        ;

    bbl::Class<OCIO_NAMESPACE::CPUProcessorRcPtr>("CPUProcessorRcPtr")
        .smartptr_to<OCIO_NAMESPACE::CPUProcessor>()
        .m(&OCIO_NAMESPACE::CPUProcessorRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstCPUProcessorRcPtr>("ConstCPUProcessorRcPtr")
        .smartptr_to<OCIO_NAMESPACE::CPUProcessor const>()
        .m(&OCIO_NAMESPACE::ConstCPUProcessorRcPtr::get)
        ;

    bbl::Class<OCIO_NAMESPACE::GPUProcessor>()
        .m(&OCIO_NAMESPACE::GPUProcessor::isNoOp)
        .m(&OCIO_NAMESPACE::GPUProcessor::hasChannelCrosstalk)
        .m(&OCIO_NAMESPACE::GPUProcessor::getCacheID)
        .m((void (OCIO_NAMESPACE::GPUProcessor::*)(OCIO_NAMESPACE::GpuShaderDescRcPtr&) const)
            &OCIO_NAMESPACE::GPUProcessor::extractGpuShaderInfo)
        .m((void (OCIO_NAMESPACE::GPUProcessor::*)(OCIO_NAMESPACE::GpuShaderCreatorRcPtr&) const)
            &OCIO_NAMESPACE::GPUProcessor::extractGpuShaderInfo, "extractGpuShaderInfo_const")
        ;

    bbl::Class<OCIO_NAMESPACE::GPUProcessorRcPtr>("GPUProcessorRcPtr")
        .smartptr_to<OCIO_NAMESPACE::GPUProcessor>()
        .m(&OCIO_NAMESPACE::GPUProcessorRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstGPUProcessorRcPtr>("ConstGPUProcessorRcPtr")
        .smartptr_to<OCIO_NAMESPACE::GPUProcessor const>()
        .m(&OCIO_NAMESPACE::ConstGPUProcessorRcPtr::get)
        ;

    bbl::Class<OCIO_NAMESPACE::Float3>("Float3")
        ;

    bbl::Class<OCIO_NAMESPACE::GpuShaderCreator>()
        .m(&OCIO_NAMESPACE::GpuShaderCreator::clone)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::getUniqueID)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::setUniqueID)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::getLanguage)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::setLanguage)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::getFunctionName)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::setFunctionName)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::getPixelName)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::setPixelName)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::getResourcePrefix)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::setResourcePrefix)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::begin)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::end)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::setTextureMaxWidth)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::getTextureMaxWidth)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::getNextResourceIndex)
        .m((bool (OCIO_NAMESPACE::GpuShaderCreator::*)(char const*, OCIO_NAMESPACE::GpuShaderCreator::DoubleGetter const&))
            &OCIO_NAMESPACE::GpuShaderCreator::addUniform, "addUniform_double")
        .m((bool (OCIO_NAMESPACE::GpuShaderCreator::*)(char const*, OCIO_NAMESPACE::GpuShaderCreator::BoolGetter const&))
            &OCIO_NAMESPACE::GpuShaderCreator::addUniform, "addUniform_bool")
        .m((bool (OCIO_NAMESPACE::GpuShaderCreator::*)(char const*, OCIO_NAMESPACE::GpuShaderCreator::Float3Getter const&))
            &OCIO_NAMESPACE::GpuShaderCreator::addUniform, "addUniform_float3")
        .m((bool (OCIO_NAMESPACE::GpuShaderCreator::*)(char const*, OCIO_NAMESPACE::GpuShaderCreator::SizeGetter const&, OCIO_NAMESPACE::GpuShaderCreator::VectorIntGetter const&))
            &OCIO_NAMESPACE::GpuShaderCreator::addUniform, "addUniform_vector_int")
        .m((bool (OCIO_NAMESPACE::GpuShaderCreator::*)(char const*, OCIO_NAMESPACE::GpuShaderCreator::SizeGetter const&, OCIO_NAMESPACE::GpuShaderCreator::VectorFloatGetter const&))
            &OCIO_NAMESPACE::GpuShaderCreator::addUniform, "addUniform_vector_float")

        .m(&OCIO_NAMESPACE::GpuShaderCreator::addDynamicProperty)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::getNumDynamicProperties)
        .m((OCIO_NAMESPACE::DynamicPropertyRcPtr (OCIO_NAMESPACE::GpuShaderCreator::*)(unsigned) const)
            &OCIO_NAMESPACE::GpuShaderCreator::getDynamicProperty)
        .m((OCIO_NAMESPACE::DynamicPropertyRcPtr (OCIO_NAMESPACE::GpuShaderCreator::*)(OCIO_NAMESPACE::DynamicPropertyType) const)
            &OCIO_NAMESPACE::GpuShaderCreator::getDynamicProperty, "getDyanmicProperty_by_type")
        .m(&OCIO_NAMESPACE::GpuShaderCreator::hasDynamicProperty)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::addTexture)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::add3DTexture)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::addToDeclareShaderCode)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::addToHelperShaderCode)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::addToFunctionShaderCode)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::addToFunctionHeaderShaderCode)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::addToFunctionFooterShaderCode)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::createShaderText)
        .m(&OCIO_NAMESPACE::GpuShaderCreator::finalize)
        ;

    bbl::Class<OCIO_NAMESPACE::GpuShaderCreatorRcPtr>("GpuShaderCreatorRcPtr")
        .smartptr_to<OCIO_NAMESPACE::GpuShaderCreator>()
        .m(&OCIO_NAMESPACE::GpuShaderCreatorRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstGpuShaderCreatorRcPtr>("ConstGpuShaderCreatorRcPtr")
        .smartptr_to<OCIO_NAMESPACE::GpuShaderCreator const>()
        .m(&OCIO_NAMESPACE::ConstGpuShaderCreatorRcPtr::get)
        ;

    bbl::Class<OCIO_NAMESPACE::GpuShaderDesc>()
        .m(&OCIO_NAMESPACE::GpuShaderDesc::CreateShaderDesc)
        .m(&OCIO_NAMESPACE::GpuShaderDesc::getNumUniforms)
        .m(&OCIO_NAMESPACE::GpuShaderDesc::getUniform)
        .m(&OCIO_NAMESPACE::GpuShaderDesc::getNumTextures)
        .m(&OCIO_NAMESPACE::GpuShaderDesc::getTexture)
        .m(&OCIO_NAMESPACE::GpuShaderDesc::getTextureValues)
        .m(&OCIO_NAMESPACE::GpuShaderDesc::getNum3DTextures)
        .m(&OCIO_NAMESPACE::GpuShaderDesc::get3DTexture)
        .m(&OCIO_NAMESPACE::GpuShaderDesc::get3DTextureValues)
        ;

    bbl::Class<OCIO_NAMESPACE::GpuShaderDescRcPtr>("GpuShaderDescRcPtr")
        .smartptr_to<OCIO_NAMESPACE::GpuShaderDesc>()
        .m(&OCIO_NAMESPACE::GpuShaderDescRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstGpuShaderDescRcPtr>("ConstGpuShaderDescRcPtr")
        .smartptr_to<OCIO_NAMESPACE::GpuShaderDesc const>()
        .m(&OCIO_NAMESPACE::ConstGpuShaderDescRcPtr::get)
        ;

    bbl::Class<OCIO_NAMESPACE::GpuShaderDesc::UniformData>("GpuShaderDescUniformData")
        ;

    bbl::Enum<OCIO_NAMESPACE::GpuShaderCreator::TextureType>("GpuShaderCreatorTextureType").prefix("");

    bbl::Class<OCIO_NAMESPACE::GpuShaderCreator::DoubleGetter>("GpuShaderCreatorDoubleGetter");
    bbl::Class<OCIO_NAMESPACE::GpuShaderCreator::BoolGetter>("GpuShaderCreatorBoolGetter");
    bbl::Class<OCIO_NAMESPACE::GpuShaderCreator::Float3Getter>("GpuShaderCreatorFloat3Getter");
    bbl::Class<OCIO_NAMESPACE::GpuShaderCreator::SizeGetter>("GpuShaderCreatorSizeGetter");
    bbl::Class<OCIO_NAMESPACE::GpuShaderCreator::VectorIntGetter>("GpuShaderCreatorVectorIntGetter");
    bbl::Class<OCIO_NAMESPACE::GpuShaderCreator::VectorFloatGetter>("GpuShaderCreatorVectorFloatGetter");

    bbl::Enum<OCIO_NAMESPACE::OptimizationFlags>().prefix("");

    bbl::Class<OCIO_NAMESPACE::ProcessorMetadata>()
        .m(&OCIO_NAMESPACE::ProcessorMetadata::Create)
        .m(&OCIO_NAMESPACE::ProcessorMetadata::getNumFiles)
        .m(&OCIO_NAMESPACE::ProcessorMetadata::getFile)
        .m(&OCIO_NAMESPACE::ProcessorMetadata::getNumLooks)
        .m(&OCIO_NAMESPACE::ProcessorMetadata::getLook)
        .m(&OCIO_NAMESPACE::ProcessorMetadata::addLook)
        .m(&OCIO_NAMESPACE::ProcessorMetadata::addFile)
        ;

    bbl::Class<OCIO_NAMESPACE::ProcessorMetadataRcPtr>("ProcessorMetadataRcPtr")
        .smartptr_to<OCIO_NAMESPACE::ProcessorMetadata>()
        .m(&OCIO_NAMESPACE::ProcessorMetadataRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstProcessorMetadataRcPtr>("ConstProcessorMetadataRcPtr")
        .smartptr_to<OCIO_NAMESPACE::ProcessorMetadata const>()
        .m(&OCIO_NAMESPACE::ConstProcessorMetadataRcPtr::get)
        ;


    bbl::Enum<OCIO_NAMESPACE::ProcessorCacheFlags>().prefix("");

    bbl::Enum<OCIO_NAMESPACE::ReferenceSpaceType>().prefix("");

    bbl::Enum<OCIO_NAMESPACE::SearchReferenceSpaceType>().prefix("");

    bbl::Class<OCIO_NAMESPACE::SystemMonitors>()
        .m(&OCIO_NAMESPACE::SystemMonitors::Get)
        .m(&OCIO_NAMESPACE::SystemMonitors::isSupported)
        .m(&OCIO_NAMESPACE::SystemMonitors::getNumMonitors)
        .m(&OCIO_NAMESPACE::SystemMonitors::getMonitorName)
        .m(&OCIO_NAMESPACE::SystemMonitors::getProfileFilepath)
        ;

    bbl::Class<OCIO_NAMESPACE::SystemMonitorsRcPtr>("SystemMonitorsRcPtr")
        .smartptr_to<OCIO_NAMESPACE::SystemMonitors>()
        .m(&OCIO_NAMESPACE::SystemMonitorsRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstSystemMonitorsRcPtr>("ConstSystemMonitorsRcPtr")
        .smartptr_to<OCIO_NAMESPACE::SystemMonitors const>()
        .m(&OCIO_NAMESPACE::ConstSystemMonitorsRcPtr::get)
        ;


    bbl::Class<OCIO_NAMESPACE::Transform>()
        ;

    bbl::Class<OCIO_NAMESPACE::TransformRcPtr>("TransformRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Transform>()
        .m(&OCIO_NAMESPACE::TransformRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstTransformRcPtr>("ConstTransformRcPtr")
        .smartptr_to<OCIO_NAMESPACE::Transform const>()
        .m(&OCIO_NAMESPACE::ConstTransformRcPtr::get)
        ;

    bbl::Enum<OCIO_NAMESPACE::TransformDirection>().prefix("");
    bbl::Enum<OCIO_NAMESPACE::TransformType>().prefix("");

    bbl::Class<OCIO_NAMESPACE::ViewingRules>()
        .m(&OCIO_NAMESPACE::ViewingRules::Create)
        .m(&OCIO_NAMESPACE::ViewingRules::createEditableCopy)
        .m(&OCIO_NAMESPACE::ViewingRules::getNumEntries)
        .m(&OCIO_NAMESPACE::ViewingRules::getIndexForRule)
        .m(&OCIO_NAMESPACE::ViewingRules::getName)
        .m(&OCIO_NAMESPACE::ViewingRules::getNumColorSpaces)
        .m(&OCIO_NAMESPACE::ViewingRules::getColorSpace)
        .m(&OCIO_NAMESPACE::ViewingRules::addColorSpace)
        .m(&OCIO_NAMESPACE::ViewingRules::removeColorSpace)
        .m(&OCIO_NAMESPACE::ViewingRules::getNumEncodings)
        .m(&OCIO_NAMESPACE::ViewingRules::getEncoding)
        .m(&OCIO_NAMESPACE::ViewingRules::addEncoding)
        .m(&OCIO_NAMESPACE::ViewingRules::removeEncoding)
        .m(&OCIO_NAMESPACE::ViewingRules::getNumCustomKeys)
        .m(&OCIO_NAMESPACE::ViewingRules::getCustomKeyName)
        .m(&OCIO_NAMESPACE::ViewingRules::getCustomKeyValue)
        .m(&OCIO_NAMESPACE::ViewingRules::setCustomKey)
        .m(&OCIO_NAMESPACE::ViewingRules::insertRule)
        .m(&OCIO_NAMESPACE::ViewingRules::removeRule)
        ;

    bbl::Class<OCIO_NAMESPACE::ViewingRulesRcPtr>("ViewingRulesRcPtr")
        .smartptr_to<OCIO_NAMESPACE::ViewingRules>()
        .m(&OCIO_NAMESPACE::ViewingRulesRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstViewingRulesRcPtr>("ConstViewingRulesRcPtr")
        .smartptr_to<OCIO_NAMESPACE::ViewingRules const>()
        .m(&OCIO_NAMESPACE::ConstViewingRulesRcPtr::get)
        ;

    bbl::Class<OCIO_NAMESPACE::ViewTransform>()
        .m(&OCIO_NAMESPACE::ViewTransform::Create)
        .m(&OCIO_NAMESPACE::ViewTransform::createEditableCopy)
        .m(&OCIO_NAMESPACE::ViewTransform::getName)
        .m(&OCIO_NAMESPACE::ViewTransform::setName)
        .m(&OCIO_NAMESPACE::ViewTransform::getFamily)
        .m(&OCIO_NAMESPACE::ViewTransform::setFamily)
        .m(&OCIO_NAMESPACE::ViewTransform::getDescription)
        .m(&OCIO_NAMESPACE::ViewTransform::setDescription)
        .m(&OCIO_NAMESPACE::ViewTransform::hasCategory)
        .m(&OCIO_NAMESPACE::ViewTransform::addCategory)
        .m(&OCIO_NAMESPACE::ViewTransform::removeCategory)
        .m(&OCIO_NAMESPACE::ViewTransform::getNumCategories)
        .m(&OCIO_NAMESPACE::ViewTransform::getCategory)
        .m(&OCIO_NAMESPACE::ViewTransform::clearCategories)
        .m(&OCIO_NAMESPACE::ViewTransform::getReferenceSpaceType)
        .m(&OCIO_NAMESPACE::ViewTransform::getTransform)
        .m(&OCIO_NAMESPACE::ViewTransform::setTransform)
        ;

    bbl::Class<OCIO_NAMESPACE::ViewTransformRcPtr>("ViewTransformRcPtr")
        .smartptr_to<OCIO_NAMESPACE::ViewTransform>()
        .m(&OCIO_NAMESPACE::ViewTransformRcPtr::get)
        ;
    bbl::Class<OCIO_NAMESPACE::ConstViewTransformRcPtr>("ConstViewTransformRcPtr")
        .smartptr_to<OCIO_NAMESPACE::ViewTransform const>()
        .m(&OCIO_NAMESPACE::ConstViewTransformRcPtr::get)
        ;

    bbl::Enum<OCIO_NAMESPACE::ViewTransformDirection>().prefix("");

    bbl::Enum<OCIO_NAMESPACE::ViewType>().prefix("");

    bbl::Class<std::string>("string");
    bbl::Class<std::istream>("istream");
    bbl::Class<std::ostream>("ostream");
}

#endif