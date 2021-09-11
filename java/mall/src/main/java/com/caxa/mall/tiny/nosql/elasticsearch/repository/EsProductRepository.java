package com.caxa.mall.tiny.nosql.elasticsearch.repository;

import com.caxa.mall.tiny.nosql.elasticsearch.document.EsProduct;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.elasticsearch.repository.ElasticsearchRepository;

public interface EsProductRepository extends ElasticsearchRepository<EsProduct,Long> {
    Page<EsProduct> findByNameOrSubtitleOrKeywords(String name, String subtitle, String keywords, Pageable page);
}
