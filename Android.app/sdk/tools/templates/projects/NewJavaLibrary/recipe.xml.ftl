<?xml version="1.0"?>
<recipe>
<#if isGradle == "true">
    <merge from="settings.gradle.ftl"
             to="${topOut}/settings.gradle" />
    <instantiate from="build.gradle.ftl"
                   to="${projectOut}/build.gradle" />
</#if>
    <instantiate from="/src/library_package/Placeholder.java.ftl"
                   to="${srcOut}/${className}.java" />
</recipe>
