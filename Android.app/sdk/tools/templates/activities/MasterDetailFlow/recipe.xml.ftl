<?xml version="1.0"?>
<recipe>
    <merge from="AndroidManifest.xml.ftl"
             to="${manifestOut}/AndroidManifest.xml" />

    <merge from="res/values-large/refs.xml.ftl"
             to="${resOut}/values-large/refs.xml" />
    <merge from="res/values-sw600dp/refs.xml.ftl"
             to="${resOut}/values-sw600dp/refs.xml" />
    <merge from="res/values/strings.xml.ftl"
             to="${resOut}/values/strings.xml" />

    <instantiate from="res/layout/activity_content_detail.xml.ftl"
                   to="${resOut}/layout/activity_${detail_name}.xml" />
    <instantiate from="res/layout/activity_content_list.xml.ftl"
                   to="${resOut}/layout/activity_${collection_name}.xml" />
    <instantiate from="res/layout/activity_content_twopane.xml.ftl"
                   to="${resOut}/layout/activity_${extractLetters(objectKind?lower_case)}_twopane.xml" />
    <instantiate from="res/layout/fragment_content_detail.xml.ftl"
                   to="${resOut}/layout/fragment_${detail_name}.xml" />

    <instantiate from="src/app_package/ContentDetailActivity.java.ftl"
                   to="${srcOut}/${DetailName}Activity.java" />
    <instantiate from="src/app_package/ContentDetailFragment.java.ftl"
                   to="${srcOut}/${DetailName}Fragment.java" />
    <instantiate from="src/app_package/ContentListActivity.java.ftl"
                   to="${srcOut}/${CollectionName}Activity.java" />
    <instantiate from="src/app_package/ContentListFragment.java.ftl"
                   to="${srcOut}/${CollectionName}Fragment.java" />
    <instantiate from="src/app_package/dummy/DummyContent.java.ftl"
                   to="${srcOut}/dummy/DummyContent.java" />
</recipe>
